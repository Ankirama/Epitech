__author__ = 'ankirama'

import myAlgos

class Ghost:
    def __init__(self, position, width, height):
        self._position = position
        self.algo = myAlgos.Djihadist(width)
        self.width = width
        self.height = height

    def __unicode__(self):
        return u'I\'m an unicorn yeah!'

    def getPosition(self):
        return self._position

    def update(self, graph, map, pacmanPos):
        old = self._position
        tmp = self.algo.nextMoves(graph, old, pacmanPos)
        if (len(tmp) > 1):
            self._position = tmp[1]
            map[old // self.width][old % self.width] = '0'
            map[self._position // self.width][self._position % self.width] = 'F'
            if self._position == pacmanPos:
                return True
        return False
