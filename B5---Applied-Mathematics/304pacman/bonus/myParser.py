# -*- coding: utf-8 -*-
__author__ = 'ankirama'

import myErrors, sys

class Parser:
    def __init__(self):
        self.map = list()
        self.ghosts = list()
        self.width = 0
        self.height = 0
        self.pacman = None

    def _parseLine(self, y, line):
        self.append = self.map.append([])
        for x, case in enumerate(line):
            if (case == 'F'):
                self.ghosts.append(y * self.width + x)
            elif (case == 'P' and not self.pacman):
                self.pacman = y * self.width + x
            elif (case != '0' and case != '1'):
                myErrors.error_message('error: [%s]: wrong line' % line)
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
                myErrors.error_message()
            for y, line in enumerate(lines):
                self._parseLine(y, line)
                self.height += 1
        except IOError as e:
            myErrors.error_message('error: [%s]: ' % file + e.strerror)
        except BaseException as e:
            print(e)
            myErrors.error_message('error: [%s]: ' % file)

    def getMap(self):
        return self.map

    def formatMap(self, c1, c2):
        for j, line in enumerate(self.map):
            for i, case in enumerate(line):
                if case == '0':
                    self.map[j][i] = c2
                elif case == '1':
                    self.map[j][i] = c1

    def displayMap(self):
        for j, line in enumerate(self.map):
            tmp = ''
            for i, case in enumerate(line):
                tmp += case
            print(tmp)

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
