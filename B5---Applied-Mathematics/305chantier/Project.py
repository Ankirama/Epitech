# -*- coding: latin-1 -*-
__author__ = 'ankirama'

import sys
from Task import Task

class Project:
    def __init__(self):
        '''
        Constructor for the Graph class
        '''
        self._tasks = {}

    def error_message(self, msg='graph error', code_error=84):
        '''
        Write an error message on stderr and exit the program with code 84
        :param msg: message we will display on our stderr
        :param code_error: code error we will use to exit
        '''
        sys.stderr.write(msg + '\n')
        sys.exit(code_error)

    def addTask(self, id):
        '''
        add a task with an id (like 'Ter')
        if a task with the same name already exists, return False
        :param id: task's id like 'Ter'
        :return: False if any error
        '''
        if id in self._tasks or len(id) == 0:
            self.error_message()
        self._tasks[id] = Task()
        self._tasks[id].setCode(id)

    def addListPrerequis(self, id, lst):
        '''
        add prerequis list in a task
        return false if task doesn't exists
        :param id: task's id like 'Ter'
        :param lst: prerequis list
        :return: False if any error
        '''
        if not id in self._tasks or len(lst) == 0:
            self.error_message()
        else:
            self._tasks[id].setPre(lst)

    def addTime(self, id, time):
        '''
        add time in a task
        return false if task doesn't exists
        :param id: task's id like 'Ter'
        :param time: time to finish the task
        :return: False if any error
        '''
        if not id in self._tasks or len(time) == 0:
            self.error_message()
        else:
            self._tasks[id].setTime(time)

    def addDesc(self, id, desc):
        '''
        add description in a task
        return false if task doesn't exists
        :param id: task's id like 'Ter'
        :param desc: description like 'terrasement'
        :return: False if any error
        '''
        if not id in self._tasks or len(desc) == 0:
            self.error_message()
        else:
            self._tasks[id].setDesc(desc)

    def getTasks(self):
        '''
        return all tasks (the dictionnary)
        :return: tasks
        '''
        return self._tasks

    def getTask(self, id):
        '''
        get a specific task by its id
        return False if any error
        :param id: task's id like 'Ter'
        :return: specific task or False
        '''
        if not id in self._tasks or len(id) == 0:
            self.error_message()
        else:
            return self._tasks[id]
