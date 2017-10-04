#!/usr/bin/python2.7

from pylab import *

def     display_graph(x, y):
    '''display our graph'''
    plot(x, y)
    show()

def     display_point(x, y):
    '''display point in our graph'''
    plot(x, y, 'b,')
    show()
