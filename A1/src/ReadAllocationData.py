## @file ReadAllocationData.py
#  @wengy12
#  @brief
#  @01/25/2019, I'm really sorry for late code :(

def readStdnts(s):
    file = open(s, "r") #input format will be "macid,fname,lname,gender,gpa,choice,choice,choice/n"
    inp = file.readlines()
    lst = []
    for i in inp:
        elm = i.split(',')
        elm[7].pop() #delete the last \n element
        newstd = {"macid": elm[0], "fname": elm[1], "lname": elm[2], "gender": elm[3], "gpa": float(elm[4]), "choice": [elm[5], elm[6], elm[7]]}
        lst.append(newstd);
    return lst

def readFreeChoice(s):
    file = open(s, "r") #input format will be "macid/n"
    inp = file.readlines()
    return inp

def readDeptCapacity(s):
    file = open(s, "r") #input format will be "faculty_name,capacity/n"
    inp = file.readlines()
    lst = []
    for i in inp:
        elm = i.split(',')
        elm[1].pop() #delete the last \n element
        newelm = {"dept": elm[1]}
        lst.append(newelm);
    return lst
