from heapq import heappop, heappush

class Djihadist:
    def __init__(self, width):
        self.width = width

    def _recreateList(self, lst):
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

    def nextMoves(self, graph, start, end):
        '''
        @brief: return next moves to play for a ghost until pacman move
        first element in the list is start and last is end
        :param start: ghost's position (y * width + x)
        :param end: pacman's position (y * width + x)
        :return: list with moves to play until new pacman move
        '''
        try:
            element = (0, start, ())
            heap = [element]
            visited = []
            while True:
                element = heappop(heap)
                if element[1] not in visited:
                    visited.append(element[1])
                    if element[1] == end:
                        lst = list(self._recreateList(element[2]))[::-1]
                        lst.append(element[1])
                        return lst
                    tmp_tuple = (element[1], element[2])
                    for head in graph[element[1]]:
                        if head not in visited:
                            tmp = (element[0] + 1, head, tmp_tuple)
                            heappush(heap, tmp)
        except IndexError:
            return list()
