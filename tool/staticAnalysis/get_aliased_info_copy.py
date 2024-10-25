#!/usr/bin/env python3

import os
import sys
import argparse
import re
import itertools
import numpy as np

#PREFIX = os.environ['STATIC_ANALYSIS_KERNEL_DIR']
PREFIX = ""

parser = argparse.ArgumentParser(description='Get aliased pair from the SVF result.')
parser.add_argument('mssa')
parser.add_argument('--aset', dest='aset', action='store_true')

args = parser.parse_args()

mssa = args.mssa
aset = args.aset

def remove_column(text):
    if aset:
        return text
    toks = text.split(':')
    if len(toks) < 3:
        return text + ":0"
    toks[2] = '0'
    return ':'.join(toks)

def strip_start(text, prefix):
    if not text.startswith(prefix):
        return text
    ret = text[-(len(text) - len(prefix)):]
    if ret.startswith("./"):
        return ret[2:]
    return ret

class Instruction:
    def __init__(self):
        self.load_from = set()
        self.store_to = set()
        self.source_loc = None
        self.poitner_type = None
        self.inwhichfunction = None #kl add

    def is_integer(self):
        return self.poitner_type in ['i8', 'i16', 'i32', 'i64']

    def is_general_pointer(self):
        return self.poitner_type in ['i8*', 'i16*', 'i32*', 'i64*']

    def extract_type(self, line):
        typ = line[line.find("({") + 2 : line.find("})")]
        for regex in re.findall('struct\.[^\ ]*\.[0-9]+[^\ \*]*', typ):
            newregex = re.sub(r'\.[0-9]+$', '', regex)
            typ = typ.replace(regex, newregex)
        for regex in re.findall('\.[0-9]+:', typ):
            newregex = re.sub(r'\.[0-9]+:', ':', regex)
            typ = typ.replace(regex, newregex)
        self.poitner_type = typ

    def extract_source_location(self, line):
        loc = line.strip().split("[[")[1]
        if loc.find("@[") != -1:
            # It is inlined at somewhere, but I don't care where it is inlined at
            delim = "@["
        else:
            # No inlined
            delim = "]]"
        self.source_loc = loc.split(delim)[0].strip()

    def __parse_pts(line):
        line = line.strip()
        line = line[line.index("{") + 1 : len(line) - 1]
        return set(map(int, line.split()))

    def feed_line(self, line, is_write):
        pts = Instruction.__parse_pts(line)#pts是point set，_parse函数负责解析
        if is_write:
            self.store_to |= pts
        else:
            self.load_from |= pts

    def get_accessed_memory_location(self):
        return list(zip(self.store_to, [True]*len(self.store_to))) + \
                list(zip(self.load_from, [False]*len(self.load_from)))

    def get_source_location(self):
        return remove_column(strip_start(self.source_loc, PREFIX))

    def get_pointer_type(self):
        return self.poitner_type
    
    def get_current_function(self,function):#kl add
        self.inwhichfunction = function

class MemoryLocation:
    def __init__(self, id):
        self.id = id
        self.load_insn = set()
        self.store_insn = set()
        self.functions = set()

    def add_instruction(self, insn, is_write,function_name):
        source_loc = insn.get_source_location()[:-2]
        if is_write:
            self.store_insn.add((source_loc,function_name))
        else:
            self.load_insn.add((source_loc,function_name))
        # self.functions.add(function_name)

    def generate_result(self):
        if aset:
            return self.__generate_aliased_set()
        else:
            return self.__generate_mempair()

    def __generate_aliased_set(self):
        return self.id, \
                list(self.load_insn) + list(self.store_insn), \
                ['R']*len(self.load_insn) + ['W']*len(self.store_insn)

    def __generate_mempair(self):
        st_st = list(itertools.product(self.store_insn, self.store_insn))
        st_ld = list(itertools.product(self.store_insn, self.load_insn))
        
        return self.id, \
                (st_st + st_ld), \
                [('W', 'W')]*len(st_st) + [('W', 'R')]*len(st_ld)

class MempairResult:
    def __init__(self):
        self.deduped_mempair = {}

    def __sort(mempair, typ):
        if mempair[0] > mempair[1]:
            return (mempair[1], mempair[0]), (typ[1], typ[0])
        return mempair, typ

    def add(self, locid, mempairs, types):
        for mempair,typ in zip(mempairs, types):
            sorted_mempair, sorted_typ = MempairResult.__sort(mempair, typ)
            sorted_typ = sorted_typ + (locid, locid) # add locid (wcventure)
            self.deduped_mempair[sorted_mempair] = sorted_typ

    def print_all(self):
        for mempair, typ in sorted(self.deduped_mempair.items()):
            print(mempair[0], mempair[1], typ[0], typ[1], typ[2], typ[3]) # add locid (wcventure)

class AliasedSetResult:
    def __init__(self):
        self.aliased_set_per_memloc = {}

    class AliasedSet:
        def __init__(self, aliased_set, typ):
            self.set = set()
            for source_loc, typ in zip(aliased_set, types):
                self.set.add((source_loc, typ))

        def __iter__(self):
            return self.set.__iter__()

    def __is_subset(self, sub_memlocid, super_memlocid):
        for insn in self.aliased_set_per_memloc[sub_memlocid]:
            if not insn in self.aliased_set_per_memloc[super_memlocid]:
                return False
        return True

    def __remove_duplicate(self, memlocid):
        for other_memlocid in list(self.aliased_set_per_memloc):
            if other_memlocid != memlocid and self.__is_subset(memlocid, other_memlocid):
                del self.aliased_set_per_memloc[memlocid]
                return
        for other_memlocid in list(self.aliased_set_per_memloc):
            if other_memlocid != memlocid and self.__is_subset(other_memlocid, memlocid):
                del self.aliased_set_per_memloc[other_memlocid]

    def add(self, memlocid, aliased_set, types):
        if len(aliased_set) == 1:
            return
        self.aliased_set_per_memloc[memlocid] = AliasedSetResult.AliasedSet(aliased_set, types)
        self.__remove_duplicate(memlocid)

    def print_all(self):
        for memlocid, aliased_set in sorted(self.aliased_set_per_memloc.items()):
            print("[Memory location ID: %d]" % memlocid[0])
            for insn in sorted(aliased_set, key = lambda x: (x[1], x[0])):
                print("\tType: ", insn[1], "\t", insn[0])

if __name__ == '__main__':
    with open(mssa, 'r') as mssa_file:
        memory_locations = {}
        memory_locationsFullKey = {}
        reset = True
        # FunctionList = []
        CurrentFunc = None
        regex_pattern = r'^==========FUNCTION: (\w+)==========$'
        for line in mssa_file:
            
            if "FUNCTION" in line:
                match = re.match(regex_pattern, line.strip())
                if match:
                    CurrentFunc =  match.group(1)
            ## KL FunctionName Catch
            if "@[" and "]]]" in line:
                continue
            if "cpp:0]]" in line:
                continue
            if len(line.strip()) == 0:
                continue
            if reset:
                reset = False
                insn = Instruction()
                insn
            ## LD = LOAD ST=STORE

            if "LDMU" in line:
                insn.feed_line(line, is_write= False)
            elif "STCHI" in line:
                insn.feed_line(line, is_write= True)        
            elif "[[" in line:
                reset = True
                # set a source location
                insn.extract_source_location(line)
                # set a type of the pointer
                insn.extract_type(line)

                insn.get_current_function(CurrentFunc)
                # set the functionname kl add

                # if insn.is_integer() or insn.is_general_pointer():
                #     continue

                typ = insn.get_pointer_type()
                for memloc, is_write in insn.get_accessed_memory_location():
                    if memloc == 1:
                        continue
                    #key = (memloc, typ)
                    key = (memloc)
                    if not key in memory_locations:
                        memory_locations[key] = MemoryLocation(key)
                    memory_locations[key].add_instruction(insn, is_write,CurrentFunc)
                    # FunctionList.append(CurrentFunc)
    SaveList = []
    for key in memory_locations:
        SaveList.append([key,memory_locations[key].store_insn,memory_locations[key].load_insn])

    # save list
    savenpylist = np.array(SaveList)
    np.save('memGroup.npy',savenpylist)
    
    # load list
    #loadedList=np.load('memGroup.npy', allow_pickle=True)
    #memGroupList=loadedList.tolist()
    #print(memGroupList)
        
    locSet = set()

    # for each in SaveList:
    #     print(each)
#krystalRay ↑ print the total info

    #     for eachstore in each[1]:
    #         locSet.add(eachstore)
    #         # locSet.add("store/write")
    #     for eachload in each[2]:
    #         locSet.add(eachload)
    #         # locSet.add("load/read")
    #     for eachfunc in each[3]:
    #         locSet.add(eachfunc)
    #         # locSet.add("Function")

    # for each in sorted(locSet):
    #     if "/usr/lib/gcc/x86_64-linux-gnu" not in each and not each.endswith(":0"):
    #         print(each)
    triples = []

    for each in SaveList:
        address,storelistset,loadlistset = each
        
        # print(address)
        # print("store:")
        for i in storelistset:
            # print(i)
            tmptriple = [address,"W",i[0],i[1]]
            triples.append(tmptriple)
        # print("load:")
        for i in loadlistset:
            # print(i)
            tmptriple = [address,"R",i[0],i[1]]
            triples.append(tmptriple)
#krystalRay ↑ print the detailed info
    for i in triples:
        print(i)
    # # 打印简化的结果
    # for triple in simplified_triples:
    #     print(triple)
