'''
This module represents a Serialised-Bounded-Periods scheduling method.
By using this method, every generated scheduling has exictly
the specified number of periods, p (or the number of periods in the
sched, or the pattern, which is the biggest).
ONLY kps from a same thread can be scheduled into a same period, while
two adjacent periods should always have kps from different threads.
Such a schedule enforces a serialised interleaving execution with exactly
p - 1 context switch.
'''
from bp_sched import BPSched
from sched import Sched
from functools import reduce

'''
Note: the prefix algorithm, i.e., constructing sched using sched/pattern
is available, but still need to be improved. -- MHE

DEMO: to test this class, simply use something like:

from sbp_sched import SBPSched

n = 5           # number of threads
kps = [5]       # numbers of key points in each thread
periods = n + 1 # number of periods

s = SBPSched(n, kps, periods)
for i in s:
    print(i, s.get_yield_pattern()) # print the schedule i, and the yeild pattern
'''

class SBPSched(BPSched):
    def __init__(self, n = 1, kps = [0], p = 1, sched = None, pattern = None):
        Sched._init_helper(self, n, kps, p, sched)
        for i in self._sched:
            if not i:
                raise ValueError("Invalid period(s) in the given sched!")
        self._pattern = []
        self._iter = self._first_iter
        lastPattern = -1
        pre = 1
        mustnot=set()
        self._start = len(self._sched)
        if pattern or sched:
            self._init_helper(self._n, self._kps, self._p, sched, pattern)
            if self._sched:
                lastPattern = self._pattern[-1]
                pre = len(self._sched)
                self._last = self._sched[-1][-1]
                self._lastCount = len(self._sched[-1])
                self._initsched =self._sched.copy()
                for j in self._pattern:
                    if j > lastPattern:
                        mustnot.add(j)
        if self._p != len(self._pattern):
            patterncopy=self._pattern.copy()
            sub_pattern = self._init_pattern(
                    self._n,
                    self._kp_pool,
                    self._p - len(self._pattern),
                    set(i for i in range(self._n) if self._kp_pool[i] > 0),
                    lastPattern,
                    mustnot,
                    patterncopy)
            if not sub_pattern:
                raise ValueError("Can't finish initialising pattern!")
            # print(sub_pattern)
            self._pattern += sub_pattern

        for i in range(self._n):
            if i not in self._pattern and self._kps[i] > 0:
                raise ValueError("Not all theads can be scheduled!")

        self._sched += self._init_sched(
                self._n, self._kp_pool,
                self._p - len(self._sched),
                self._pattern[len(self._sched):])
        self._prefix = [x.copy() for x in self._sched[:pre]]

    def _init_helper(self, n, kps, p, sched, pattern):
        if pattern:
            if max(pattern) > self._n:
                self._n = max(pattern)
                while len(self._kps) < self._n:
                    self._kps.append(self._kps[-1])
                    self._kp_pool.append(self._kps[-1])
            self._p = max(self._p, len(pattern))
            self._pattern = pattern.copy()

        if sched:
            sched_pattern = [x[0] for x in sched]

            # More input validation
            if not reduce(lambda x, y: x and y,
                          map(lambda x, y: x == y,
                              sched_pattern,
                              self._pattern),
                          True):
                raise ValueError("Given sched and pattern won't match!")

            if len(sched_pattern) > len(self._pattern):
                self._pattern = sched_pattern

        tmp = -1
        for i in self._pattern:
            if i == tmp:
                raise ValueError("Adjecent periods can't host same threads!")
            tmp = i
    def _init_pattern(self, n, kps, p, mustDo = None, last = -1,mustnot=None,done=None):
        if mustDo == None:
            mustDo = set(i for i in range(n) if kps[i] > 0)
        if mustnot == None:
            mustnot = set()
        if done == None:
            done =[]

        if p < 1 or p < len(mustDo):
            return None

        if p == 1:
            if len(mustDo) == 1:
                md = sorted(mustDo)
                if md[0] == last or md[0] in mustnot:
                    return None
                else:
                    return [md[0]]

            for i in range(n):
                if i == last :
                    continue
                if kps[i] <= 0:
                    continue
                if i in mustnot:
                    continue
                return [i]
            return None

        if p == len(mustDo):
            md = sorted(mustDo)
            for i in md:
                if i == last :
                    continue
                if i in mustnot:
                    return None
                mustnot_pre=mustnot.copy()
                for j in done:
                    if j > i:
                        mustnot.add(j)
                done.append(i)
                sub_done= self._init_pattern(n,kps,p-1,mustDo-{i},i,mustnot,done)
                if sub_done!=None:
                    return [i]+sub_done
                mustDo.add(i)
                done.pop()
                mustnot=mustnot_pre.copy()
            return None

        for i in range(n):
            if i in mustnot:
                continue
            if i == last :
                continue
            if kps[i] <= 0:
                continue
            mustnotpre=mustnot.copy()
            if i < last:
                for j in done:
                    if(j>i):
                        mustnot.add(j)
            rkps = kps.copy()
            rkps[i] -= 1
            done.append(i)
            sub_pattern = self._init_pattern( n, rkps, p - 1, mustDo - {i}, i, mustnot, done)
            if sub_pattern:
                return [i] + sub_pattern
            done.pop()
            mustnot=mustnotpre.copy()
        return None



    def _next_pattern(self,n, kps, p, pattern, mustDo = None, last = -1,mustnot=None,done=None):
        if mustDo == None:
            mustDo = set(i for i in range(n) if kps[i] > 0)
        if mustnot == None:
            mustnot = set()
        if done == None:
            done =[]
        if p < 1:
            return None
        if p == 1:
            if len(mustDo) > 1:
                return None
            if len(mustDo) == 1:
                candidate = mustDo.pop()
                if candidate == pattern[0] or candidate == last:
                    return None
                else:
                    return [candidate]

            for i in range(pattern[0] + 1, n):
                if i == last:
                    continue
                if kps[i] <= 0:
                    continue
                if i in mustnot:
                    continue
                return [i]
            return None

        rkps = kps.copy()
        rkps[pattern[0]] -= 1
        done.append(pattern[0])
        mustnotpre=mustnot.copy()
        if pattern[0] < last:
            for j in done:
                if(j>pattern[0]):
                    mustnot.add(j)
        sub_pattern = self._next_pattern(
                n, rkps, p - 1, pattern[1:], mustDo - {pattern[0]}, pattern[0],mustnot,done)
        if sub_pattern:
            return [pattern[0]] + sub_pattern
        mustnot=mustnotpre.copy()
        done.pop()
        for i in range(pattern[0] + 1, n):
            if i == last:
                continue
            if kps[i] <= 0:
                continue
            if i in mustnot:
                continue
            if i < last:
                for j in done:
                    if(j>i):
                        mustnot.add(j)
            rkps = kps.copy()
            rkps[i] -= 1
            done.append(i)
            sub_pattern = self._init_pattern(n, rkps, p - 1, mustDo - {i}, i,mustnot,done)
            if sub_pattern:
                return [i] + sub_pattern
            mustnot=mustnotpre.copy()
            done.pop()
        return None

    def _init_sched(self, n, kps, p, pattern):
        rlt = [[x] for x in pattern]
        k = kps.copy()
        # 去掉pattern中占用的中断点数
        for i in range(n):
            k[i] -= pattern.count(i)

        for i in range(n):
            for j in range(p - 1, -1, -1):
                if pattern[j] == i:
                    rlt[j] += [i] * k[i]
                    break
        return rlt

    def _next_sched(self, n, kps, p, sched, pattern):
        rlt = [x.copy() for x in sched]

        for i in range(n - 1, -1, -1):
            idx1 = - 1
            for j in range(p - 1, 0, -1):
                if i == pattern[j] and sched[j].count(i) > 1:
                    idx1 = j
                    break
            if idx1 == -1:
                continue
            idx2 = -1
            for j in range(idx1 - 1, -1, -1):
                if i == pattern[j]:
                    idx2 = j
                    break
            if idx2 == -1:
                continue

            rlt[idx1].remove(i)
            rlt[idx2].append(i)

            sched = self._init_sched(n, kps, p, pattern)
            for j in range(p):
                if pattern[j] <= i:
                    continue
                rlt[j] = sched[j]
            return rlt

        return None

    def _first_iter(self):
        self._iter = self._next_iter
        rlt  = [x.copy() for x in self._sched]
        return rlt

    def _next_iter(self):
        if self._start > 0:
            kp_pool= self._kp_pool.copy()
            kp_pool[self._last] += self._lastCount
            lastPattern=self._pattern[self._start-1]
            mustnot=set()
            for j in self._pattern[:self._start]:
                if j > lastPattern:
                    mustnot.add(j)
            # p = self._p - self._start + 1
            # sched = self._sched[self._start - 1:]
            # pre_sched=self._sched[:self._start-1]
            # pattern = self._pattern[self._start - 1:]
            sched = self._next_sched(self._n, kp_pool, self._p-self._start +1, self._sched[self._start - 1:], self._pattern[self._start - 1:])
            if sched == None:
                pattern = self._next_pattern(
                    self._n,
                    self._kp_pool,
                    self._p-self._start,
                    self._pattern[self._start:],
                    set(i for i in range(self._n) if self._kp_pool[i] > 0),
                    lastPattern,
                    mustnot,
                    self._pattern[:self._start]
                    )
            # print(pattern)
                if pattern == None:
                    raise StopIteration()
                else:
                    self._pattern = self._pattern[:self._start]+pattern
                    sched = self._init_sched(
                            self._n, self._kp_pool, self._p-self._start, self._pattern[self._start:])
                    sched_temp=self._initsched+sched
            else:
                sched_temp = self._sched[:self._start -1]+ sched
        else:
            # kp_pool = self._kp_pool.copy()
            # p = self._p
            # sched = self._sched.copy()
            # pattern = self._pattern.copy()
            sched = self._next_sched(self._n, self._kp_pool, self._p, self._sched, self._pattern)
            while sched == None:
                pattern = self._next_pattern(
                      self._n, self._kp_pool, self._p, self._pattern)
            # print(pattern)
                if pattern == None:
                    raise StopIteration()
                else:
                    self._pattern = pattern
                    sched = self._init_sched(
                            self._n, self._kps, self._p, self._pattern)
            sched_temp =sched
        # while sched_chosen == None:
        #     pattern = self._next_pattern(
        #             self._n,
        #             self._ckps,
        #             self._p - self._start,
        #             self._pattern[self._start:],
        #             set(self._chosen),
        #             -1 if self._start == 0 else self._pattern[self._start - 1])
        # sched = self._next_sched(
        #         self._n, self._kps, self._p,
        #         self._sched, self._pattern)
        self._prefix = []
        for i in range(len(sched_temp)):
            self._prefix.append(sched_temp[i])
            if sched_temp[i] != self._sched[i]:
                break
        self._sched =sched_temp
        rlt  = [x.copy() for x in self._sched]
        return rlt

    def next(self):
        rlt = self._iter()
        return rlt

    def get_prefix(self):
        return [x.copy() for x in self._prefix]

    def get_pattern(self):
        return self._pattern.copy()
