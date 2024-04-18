from external_def import *
from ipc import *
from interleaving import *
from bp_sched import *
from sbp_sched_mixed_end import *
from ctypes import *
import sys, struct, time

def test(scheduler, verbose = True):
    start = time.perf_counter()
    scheds = []
    count = 0
    for i in scheduler:
        if i in scheds:
            print("Duplicated!")
        scheds.append(i)
        if verbose:
            try:
                chosen = scheduler._chosen
            except:
                chosen = []
            print(i, chosen, [set(x) for x in i])
        count += 1
    print("Num of scheds: ", count)
    end = time.perf_counter()
    print("Time cost: ", end - start)


print("-----Test 1---------")
'''
[[0, 0, 0], [1], [0, 0, 0, 0, 0]]
[[0, 0, 0, 0], [1, 1], [0, 0, 0, 0]]
[[0, 0, 0, 0, 0], [1, 1], [0, 0, 0]]
[[0, 0, 0, 0, 0, 0], [1, 1], [0, 0]]
[[0, 0, 0, 0, 0, 0, 0], [1, 1], [0]]
[[1], [0, 0, 0, 0, 0, 0, 0, 0], [1]]
'''
try:
    s = SBPSched(3, [8,2,2], 3, [[0, 0, 0], [1]])
    test(s)
except Exception as e:
    print(e,'\n')