## @file AAList.py
#  @author wengy12
#  @brief
#  @date 02/11/2019

from StdntAllocTypes import *


class AALst:

    s = {}

    def __init__(self):
        for i in DeptT:
            self.s[i] = []

    def add_stdnt(self, dep, m):
        self.s[dep].append(m)

    def lst_alloc(self, d):
        print(self.s[d])

    def num_alloc(self, d):
        print(len(self.s[d]))
