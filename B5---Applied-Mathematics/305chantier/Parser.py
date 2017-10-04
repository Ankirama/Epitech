# -*- coding: latin-1 -*-
__author__ = 'ankirama'

import os, sys
from Project import Project

class Parser:
    '''
    Class to parse our file, it will check our file
    '''
    def __init__(self):
        '''
        Constructor for the class
        '''
        self._project = Project()

    def error_message(self, msg='unknown error', code_error=84):
        '''
        Write an error message on stderr and exit the program with code 84
        :param msg: message we will display on our stderr
        :param code_error: code error we will use to exit
        '''
        sys.stderr.write(msg + '\n')
        sys.exit(code_error)

    def _parseLine(self, line):
        '''
        we will parse the line if we have a correct line and add into our project
        if any error -> print on stderr + exit with code 84
        :param line: line we will parse
        :return:
        '''
        tokens = line.split(';')
        if len(tokens) < 3:
            self.error_message('error: [%s]: you must specify at least 3 elements' % (line))
        elif int(tokens[2]) and int(tokens[2]) < 0:
            self.error_message('error: [%s]: time must be >= 0' % (line))
        self._project.addTask(tokens[0])
        self._project.addDesc(tokens[0], tokens[1])
        self._project.addTime(tokens[0], tokens[2])
        if len(tokens) > 3:
            self._project.addListPrerequis(tokens[0], tokens[3:])

    def parseFile(self, file):
        '''
        Try to open our file and call _parseLine to check each line
        if any error -> print on stderr + exit with code 84
        :param file: filepath like './bonus/test/test1'
        '''
        try:
            with open(file, 'r') as f:
                data = f.readlines()
                lines = [x.rstrip('\n').decode('latin-1') for x in data]
            for x in lines:
                self._parseLine(x)
        except IOError as e:
            self.error_message('error: [%s]: %s' % (file, e.strerror))
        except BaseException:
            self.error_message('error: [%s]: Unknown error' % file)

    def getProject(self):
        '''
        get tasks from our project generated from our file (from our scrip from our directory etc...)
        :return: tasks (dictionnary)
        '''
        return self._project
