#!/usr/bin/env python3

'''
USE: ./run_dbds_lite.py  EXECUTABLE  NUM_OF_THREADS  NUM_OF_KPS_PER_THREAD
'''

import sys, subprocess, time, interleaving
from datetime import datetime
from ctypes import *

def formateTime(seconds):
    hours, rem = divmod(seconds, 3600)
    minutes, s = divmod(rem, 60)
    return '{:0>2}:{:0>2}:{:08.5f}'.format(int(hours), int(minutes), s)

exe = sys.argv[1]
N = int(sys.argv[2])    # number of threads
M = int(sys.argv[3])    # number of key points per thread

rlts = []               # the set of unique results generated by the c program
startTime = time.time()
lastTime  = time.time() # the time when a new result is found
rounds = lastRound = 0

# set up shared memory
IPC_KEY, MAP_SIZE, IPC_CREAT, IPC_EXCL = 1111, sizeof(c_int) * (2 + 10000), 512, 1024
shmget = cdll.LoadLibrary("libc.so.6").shmget
shmat = cdll.LoadLibrary("libc.so.6").shmat
shmat.restype = c_void_p
shm_id = shmget(IPC_KEY, MAP_SIZE, IPC_CREAT | IPC_CREAT | 0o666)
ADDR = shmat(shm_id, 0, 0)

# calculate the interleaving
iter = interleaving.interleaving_iter(N, [M])
for inter in iter:
    # for each interleaving, get the yield pattern
    pattern = interleaving.yield_pattern_gen(N, inter, True)

    # write the config to shared memory
    memmove(ADDR, byref(c_int(N)), sizeof(c_int))
    memmove(ADDR + sizeof(c_int), byref(c_int(M)), sizeof(c_int))
    p = []
    for t in pattern:
        p += t
    arr = (c_int * len(p))(*p)
    memmove(ADDR + sizeof(c_int) * 2, arr, sizeof(c_int) * len(p))

    # input("Press Enter to continue...")

    cmd = ['sudo', exe]
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    stdout, _ = process.communicate()
    x = stdout.split()[-1]
    rounds += 1
    # if(not x in rlts):
    rlts.append(x)
    lastRound = rounds
    lastTime = time.time()

    # if not interleaving.interleaving_next(inter):
    #     break

print(len(rlts), 'results found:')
print(rlts)
print('-' * 50)
print('\tLast New Find\t\tTotal')
print('Round\t{0}\t\t\t{1}'.format(lastRound, rounds))
print('Time\t' + formateTime(lastTime - startTime), end = "")
print('\t\t' + formateTime(time.time() - startTime))
