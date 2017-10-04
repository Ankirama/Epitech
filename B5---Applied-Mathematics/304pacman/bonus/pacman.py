import myParser, myAlgos, myErrors, myGraph
from ghost import Ghost
import sys

class Game:
    def __init__(self, file):
        self.parser = myParser.Parser()
        self.parser.parseFile(file)
        self.map = self.parser.getMap()
        self.graph = self._mapToGraph(self.map, self.parser.getWidth(), self.parser.getHeight())
        self.ghosts = []
        for ghost in self.parser.getGhosts():
            self.ghosts.append(Ghost(ghost,
                                    self.parser.getWidth(),
                                    self.parser.getHeight()))
        #create pacman class
        self.pacman = self.parser.getPacman()
        self.lifes = 3
        self.isDead = False

    def _mapToGraph(self, map, width, height):
        graph = myGraph.Graph()
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

    def run(self):
        while not self.isDead:
            self.draw()
            self.update()

    def update(self):
        '''
        @brief: it will call every update method for our ghosts and pacman
        It will update the graph after every update -> need to be optimized
        :return:
        '''
        for ghost in self.ghosts:
            if ghost.update(self.graph, self.map, self.pacman):
                self.isDead = True
                break
            self.graph = self._mapToGraph(self.map, self.parser.getWidth(), self.parser.getHeight())
            sys.exit()

    def draw(self):
        '''
        @bried: it will call every draw method for our ghosts, pacman and draw the map
        :return:
        '''
        self.parser.displayMap()
        print('---------')


def game(file):
    game = Game(file)
    game.run()

if __name__ == '__main__':
    if len(sys.argv) == 2:
        game(sys.argv[1])
    else:
        myErrors.error_message('usage: ./304pacman mapfile')