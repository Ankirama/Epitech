__author__ = 'ankirama'

from heapq import heappop, heappush

class AllStar:
    def __init__(self, width):
        self.width = width

    def _heuristic(self, xy1, xy2):
        '''
        Manhattan distance.
        Distance between 2 points in a grid based on a strictly and vertical path
        :param xy1: first point
        :param xy2: second point
        :return: the result from manhattan distance (|Xb - Xa| + |Yb - Ya|)
        '''
        xa = xy1 % self.width
        ya = xy1 // self.width
        xb = xy2 % self.width
        yb = xy2 // self.width
        return abs(xb - xa) + abs(yb - ya)

    def displayMap(self, graph, start, end, parser, c1, c2):
        costs = self._doit(graph, start, end)
        print('A star Algorithm')
        parser.resetMap(c2)
        map = parser.getMap()
        for k, v in costs.iteritems():
            if (map[k // parser.getWidth()][k % parser.getWidth()] == c1 or
                map[k // parser.getWidth()][k % parser.getWidth()] == c2):
                map[k // parser.getWidth()][k % parser.getWidth()] = str(v % 10)
        parser.displayMap(map)
        print('_________________')

    def _doit(self, graph, start, end):
        q = [(0, start)]
        costs = {start: 0}
        try:
            while True:
                _, curr = heappop(q)
                if curr == end:
                    return costs
                for neighbor in graph[curr]:
                    tmp = costs[curr] + 1
                    if neighbor not in costs or tmp < costs[neighbor]:
                        costs[neighbor] = tmp
                        high = tmp + self._heuristic(end, neighbor)
                        heappush(q, (high, neighbor))
        except IndexError:
            return {}