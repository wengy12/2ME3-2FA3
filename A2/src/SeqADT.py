## @file SeqADT.py
#  @author wengy12
#  @brief
#  @date 02/11/2019


class SeqADT:

    def __init__(self, s):
        self.s = s
        self.i = 0
        #return self

    def start(self):
        self.i = 0

    def next(self):
        if self.i >= len(self.s):
            raise StopIteration
        self.i = self.i + 1
        return self.s[self.i - 1]

    def end(self):
        return (self.i >= len(self.s))
