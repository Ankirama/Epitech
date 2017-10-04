# -*- coding: latin-1 -*-

__author__ = 'ankirama'

from Project        import Project
from Task           import Task
from collections    import OrderedDict
import sys

class Grant:
    def __init__(self, project):
        self._project = project
        self._timeTasks = dict()
        self._visited = list()
        self._sortedTimes = OrderedDict()
        self._numberWeeks = int()

    def _calcTimeId(self, id):
        if id in self._visited:
            return self._timeTasks[id]['end']
        elif len(self._project.getTask(id).getPre()) == 0:
            self._timeTasks[id] = {'start': 0, 'end': 0 + self._project.getTask(id).getTime(), 'total': self._project.getTask(id).getTime()}
            return self._timeTasks[id]['end']
        else:
            max_value = 0
            for code in self._project.getTask(id).getPre():
                max_value = max(max_value, self._calcTimeId(code))
            self._timeTasks[id] = {'start': max_value, 'end': max_value + self._project.getTask(id).getTime(), 'total': self._project.getTask(id).getTime()}
            return self._timeTasks[id]['end']

    def setTimes(self):
        for code, task in self._project.getTasks().iteritems():
            self._calcTimeId(code)
            self._numberWeeks = max(self._numberWeeks, self._timeTasks[code]['end'])

    def _sortByStartTime(self):
        self._sortedTimes = OrderedDict(sorted(self._timeTasks.items(), key=lambda t: (t[1]['start'], t[1]['total'], t[0])))

    def _displaygraph(self, code, times):
        flt = 0
        if 'flt' in times.keys():
            flt = times['flt']
        tmp = '%s\t(%d)\t' % (code, flt)
        i = 0
        timeEnd = times['start'] + times['total']
        while i < timeEnd:
            if i >= times['start']:
                tmp = tmp + '='
            else:
                tmp = tmp + ' '
            i += 1
        return tmp
    
    def displayGrantt(self):
        self._sortByStartTime()
        if self._numberWeeks <= 1:
            print(u'durée totale des travaux : %d semaine\n' % self._numberWeeks)
        else:
            print(u'durée totale des travaux : %d semaines\n' % self._numberWeeks)
        for code, times in self._sortedTimes.iteritems():
            if 'flt' in times.keys():
                tmp = u'%s doit débuter entre t=%d et t=%d' % (code, times['start'], times['start'] + times['flt'])
            else:
                tmp = u'%s doit débuter à t=%d' % (code, times['start'])
            print('%s' % tmp)
        print
        for code, times in self._sortedTimes.iteritems():
            tmp = self._displaygraph(code, times)
            print(tmp)

    '''
    Function pour trouver le plus petit temps de flottement
    '''
    def _findShortestTime(self, task):
        shortestTime = None
        for elt in self._project.getTasks():
            if task[0] in self._project.getTasks()[elt].getPre():
                timeTask = self._sortedTimes[elt]['start'] - (task[1]['total'] + task[1]['start'])
                if timeTask <= 0:
                    return False
                if shortestTime == None:
                    shortestTime = timeTask
                elif timeTask < shortestTime:
                    shortestTime = timeTask
        timeEnd = self._numberWeeks - (task[1]['total'] + task[1]['start'])
        if shortestTime == None:
            shortestTime = timeEnd
        if timeEnd < shortestTime:
            shortestTime = timeEnd
        return shortestTime
    
    '''
    On parcourt nos tâches et pour chaque tâche on cherche celles où la notre est un prérequis
    Si la fonction _findShortestTime retourne un entier c'est qu'il y a un temps de flottement et on le rajoute dans notre dictionnaire
    '''
    def _maxBeginTime(self):
        self._sortByStartTime()
        for task in self._sortedTimes.iteritems():
            time = self._findShortestTime(task)
            if time != False:
                task[1].update({'flt': time})
