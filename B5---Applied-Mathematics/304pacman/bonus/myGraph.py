__author__ = 'ankirama'

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