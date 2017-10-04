#!/usr/bin/python2.7

import numpy as np
from my_graph import *

def     it_butterfly(length, k):
    '''iterative version because python doesn't like big number :('''
    x1 = 10
    i = 1
    array = [10]
    while (i < length):
        tmp = k * array[i - 1] * (1000.0 - array[i - 1]) / 1000.0
        array.append(tmp)
        i += 1
    return (array)

def     butterfly(array, i, k):
    '''recursive function to append into our array value'''
    if (i == 1):
        array.append(10)
        return (10)
    else:
        res = butterfly(array, i - 1, k)
        life = k * res * (1000 - res) / 1000.0
        array.append(life)
        return (life)

def     my_result(imin, imax):
    '''called if ther is 2 arguments'''
    x = []
    y = []
    k = 1.0
    while (k <= 4.0):
        tmp = it_butterfly(imax, k)
        x = x + tmp[(imin - 1):]
        for _ in range (imax - imin + 1):
            y.append(k)
        k += 0.01
    display_point(y, x)

def     my_generation(k):
    '''if only 1 arg'''
    x = []
    y = []
    butterfly(x, 100, k)
    x = np.array(x)
    for i in range(len(x)):
        y.append(i + 1)
    y = np.array(y)
    display_graph(y, x)
