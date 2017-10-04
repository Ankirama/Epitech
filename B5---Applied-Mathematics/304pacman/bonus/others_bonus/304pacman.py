__author__ = 'ankirama'

import allstar
import os, sys, re

def error_message(msg='unknown error', code_error=84):
    '''
    Write an error message on stderr and exit the program with code 84
    :param msg: message we will display on our stderr
    :param code_error: code error we will use to exit
    '''
    sys.stderr.write(msg + '\n')
    sys.exit(code_error)

class Parser:
    def __init__(self):
        self.map = list()
        self.ghosts = list()
        self.width = 0
        self.height = 0
        self.pacman = None

    def _parseLine(self, y, line):
        self.map.append([])
        for x, case in enumerate(line):
            if (case == 'F'):
                self.ghosts.append(y * self.width + x)
            elif (case == 'P' and not self.pacman):
                self.pacman = y * self.width + x
            elif (case != '0' and case != '1'):
                error_message('error: [%s]: wrong line' % line)
            self.map[y].append(case)

    def parseFile(self, file):
        '''
        It will travel our lines and parse them
        '''
        try:
            with open(file, 'r') as f:
                data_tmp = f.readlines()
                lines = [x.rstrip('\n') for x in data_tmp]
            if (len(lines) > 0):
                self.width = len(lines[0])
            else:
                error_message()
            for y, line in enumerate(lines):
                self._parseLine(y, line)
                self.height += 1
        except IOError as e:
            error_message('error: [%s]: ' % file + e.strerror)
        except BaseException as e:
            print(e)
            error_message('error: [%s]: ' % file)

    def getMap(self):
        return self.map

    def formatMap(self, c1, c2):
        for j, line in enumerate(self.map):
            for i, case in enumerate(line):
                if case == '0':
                    self.map[j][i] = c2
                elif case == '1':
                    self.map[j][i] = c1

    def displayMap(self, map):
        for j, line in enumerate(map):
            tmp = ''
            for i, case in enumerate(line):
                tmp += case
            print(tmp)

    def resetMap(self, c2):
        forbidden = [str(x) for x in range(0, 10)]
        for j, line in enumerate(self.map):
            for i, case in enumerate(line):
                if case in forbidden:
                    self.map[j][i] = c2

    def getGhosts(self):
        return self.ghosts

    def getWidth(self):
        return self.width

    def getHeight(self):
        return self.height

    def getPacman(self):
        return self.pacman

    def __unicode__(self):
        return u'Parser all categories my friend'

class Graph:
    def __init__(self):
        self.nodes = dict()

    def addNode(self, node_pos):
        self.nodes.setdefault(node_pos, list())

    def addNeighbor(self, node_pos, neighbor_pos):
        self.nodes[node_pos].append(neighbor_pos)

    def getNode(self, node_pos):
        return self.nodes[node_pos]

    def getNodes(self):
        return self.nodes

def mapToGraph(map, width, height):
    graph = Graph()
    directions = [[0, -1], [1, 0], [0, 1], [-1, 0]] # North - East - South - West

    for y, line in enumerate(map):
        for x, case in enumerate(line):
            if case != '1':
                node = y * width + x
                graph.addNode(node)
                for v in directions:
                    if x + v[0] >= 0 and x + v[0] < width\
                        and y + v[1] >= 0 and y + v[1] < height\
                        and map[y + v[1]][x + v[0]] != '1':
                        graph.addNeighbor(node, (y + v[1]) * width + x + v[0])

    return graph.getNodes()

def recreateList(lst):
    '''
    @brief: It will recreate a list from a [a, [b, [c, [] ] ] ] list
    yiel will allow us to get a generator
    to generate it, we have to iterate from our list after each yiel
    :param lst: a list like [a, [b, [c, [] ] ] ]
    :return: it will generate a new list like [1, 2, 3, 4, 5]
    '''
    while len(lst) > 0:
        yield lst[0]
        lst = lst[1]

def djihadist(graph, start, end, keep):
    element = (0, start, ())
    heap = [element]
    visited = []
    while True:
        element = heap[0]
        heap = heap[1::]
        if element[1] not in visited:
            keep.append((element[1], element[0]))
            visited.append(element[1])
            if element[1] == end:
                lst = list(recreateList(element[2]))[::-1]
                lst.append(element[1])
                return lst
            tmp_tuple = (element[1], element[2])
            for head in graph[element[1]]:
                if head not in visited:
                    tmp = (element[0] + 1, head, tmp_tuple)
                    heap.append(tmp)

def djihadistDisplay(graph, start, end, parser):
    print('Dijkstra\'s Algorithm')
    lst = []
    map = list(parser.getMap())
    try:
        djihadist(graph, start, end, lst)
    except IndexError:
        error_message('unable to find a path')
    for elt in lst:
        if (map[elt[0] // parser.getWidth()][elt[0] % parser.getWidth()] == sys.argv[2] or
            map[elt[0] // parser.getWidth()][elt[0] % parser.getWidth()] == sys.argv[3]):
            map[elt[0] // parser.getWidth()][elt[0] % parser.getWidth()] = str(elt[1] % 10)
    parser.displayMap(map)
    print('___________________')

def main():
    forbidden = [str(x) for x in range(0, 10)]
    if (len(sys.argv) != 4 or len(sys.argv[2]) > 1 or len(sys.argv[2]) == 0 or len(sys.argv[3]) > 1 or len(sys.argv[3]) == 0):
        error_message('Usage: ./304pacman file c1 c2')
    elif sys.argv[2] in forbidden or sys.argv[3] in forbidden:
        error_message('error: c1 and c2 must be all except a number')
    else:
        parser = Parser()
        parser.parseFile(sys.argv[1])
        graph = mapToGraph(parser.getMap(), parser.getWidth(), parser.getHeight())
        parser.formatMap(sys.argv[2], sys.argv[3])
        algoAllstar = allstar.AllStar(parser.getWidth())
        algoAllstar.displayMap(graph, parser.getGhosts()[0], parser.getPacman(), parser, sys.argv[2], sys.argv[3])
        djihadistDisplay(graph, parser.getGhosts()[0], parser.getPacman(), parser)
        parser.resetMap(sys.argv[3])
    sys.exit(0)

if __name__ == '__main__':
    main()
