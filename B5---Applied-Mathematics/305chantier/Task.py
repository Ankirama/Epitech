# -*- coding: latin-1 -*-
__author__ = 'ankirama'

import sys

class Task:
    def __init__(self):
        self._code = str()
        self._desc = str()
        self._time = int()
        self._pre  = list()

    def displayTask(self):
        tasks = ';'.join(self._pre)
        if len(self._pre) > 0:
            tasks = '| prerequis: ' + tasks
        else:
            tasks = ''
        msg = 'code: %s | desc: %s | time: %d %s' % (self._code, self._desc, self._time, tasks)
        print(msg)

    def error_message(self, msg='task error', code_error=84):
        '''
        Write an error message on stderr and exit the program with code 84
        :param msg: message we will display on our stderr
        :param code_error: code error we will use to exit
        '''
        sys.stderr.write(msg + '\n')
        sys.exit(code_error)

    def printTask():
        print('code : ', self._code)
        print('desc : ', self._desc)
        print('time : ', self._time)
        print('pre : ', self._pre)
    
    # region Setters
    def setCode(self, code):
        self._code = code

    def setDesc(self, desc):
        self._desc = desc

    def setTime(self, time):
        try:
            self._time = int(time)
        except:
            self.error_message()

    def setPre(self, pre):
        self._pre = pre
    # endregion

    # region Getters
    def getCode(self):
        return self._code

    def getDesc(self):
        return self._desc

    def getTime(self):
        return self._time

    def getPre(self):
        return self._pre
    # endregion
