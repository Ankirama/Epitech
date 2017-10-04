#!/usr/bin/env python

import random

INFINITY = 2147483647

trace = [0 for _ in range(8)]

def resetTrace():
    global trace
    trace = [0 for _ in range(9)]

def randomize(max):
    return random.randint(1, max)

def aux(obj, trace, index):
    if (index == 0):
        return obj[index] * trace[index] < INFINITY
    else:
        return obj[index] * trace[index] < trace[index - 1] and aux(obj, trace, index - 1)

def main():
    global trace
    global INFINITY
    obj = [40, 60, 20, 40, 60, 40, 60, 100]
    res = False
    while not res:
        resetTrace()
        for i in range(len(trace)):
            if i == 0:
                trace[i] = randomize(INFINITY - 1)
            else:
                trace[i] = randomize(trace[i - 1])
        res = aux(obj, trace, len(obj) -1 )
    tmp = ''
    for i in trace:
        tmp += str(i) + ' '
    with open('res_heuristic.txt', 'w') as f:
        f.write(tmp + '\n')
    print(tmp)
    print("done")

if __name__ == '__main__':
    main()
