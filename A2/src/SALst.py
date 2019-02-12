## @file SALst.py
#  @author wengy12
#  @brief
#  @date 02/11/2019

from StdntAllocTypes import *
from AALst import *
from DCapALst import *


class sALst:

    def init(self):
        self.s = set()

    def add(self, m, i):
        for j in self.s:
            if j[0] == m:
                raise KeyError
        self.s.add((m, i))

    def remove(self, m):
        n = len(self.s)
        for i in self.s:
            if i[0] == m:
                self.s.remove(i)
        if n != len(self.s) + 1:
            raise KeyError

    def elm(self, m):
        for i in self.s:
            if i[0] == m:
                return True
        return False

    def info(self, m):
        for i in self.s:
            if i[0] == m:
                return i[1]
        raise KeyError

SALst = sALst()
