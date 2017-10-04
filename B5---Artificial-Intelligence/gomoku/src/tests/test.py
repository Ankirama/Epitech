#!/usr/bin/env python

INFINITY = 9223372036854775807

def main():
    obj = [40, 60, 20, 40, 60, 40, 60, 100]
    trace = [0 for _ in range(len(obj))]
    trace[len(obj) - 1] = 1
    for i in reversed(range(len(obj))):
        print(trace[i])
        trace[i - 1] = obj[i] * trace[i]
    print(trace[0])
    tmp = ''
    for x in trace:
        tmp += str(x) + ' '
    print(tmp)

if __name__ == '__main__':
    main()
