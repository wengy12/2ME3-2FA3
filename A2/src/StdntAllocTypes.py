## @file StdntAllocTypes.py
#  @author wengy12
#  @brief
#  @date 02/11/2019
from SeqADT import *
from enum import Enum
from typing import *


class GenT(Enum):
    male = 0
    female = 1


class DeptT(Enum):
    civil = 0
    chemical = 1
    electrical = 2
    mechanical = 3
    software = 4
    materials = 5
    engphys = 6


class SInfoT(NamedTuple):
    fname: str
    lname: str
    gender: GenT
    gpa: float
    choices: DeptT
    freechoice: bool
