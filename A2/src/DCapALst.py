## @file DCapALst.py
#  @author wengy12
#  @brief
#  @date 02/11/2019

from StdntAllocTypes import *


class dCapALst:

    def init(self):
        self.s = set()

    def add(self, d, n):
        for i in self.s:
            if i[0] == d:
                raise KeyError
        self.s.add((d, n))

    def remove(self, d):
        n = len(self.s)
        for i in self.s:
            if i[0] == d:
                self.s.remove(i)
        if n != len(self.s) + 1:
            raise KeyError

    def elm(self, d):
        for i in self.s:
            if i[0] == d:
                return True
        return False

    def capacity(self, d):
        for i in self.s:
            if i[0] == d:
                return i[1]
        raise KeyError

DCapALst = dCapALst()
