## @file testCalc.py
#  @wengy12
#  @brief
#  @01/29/2019

import random
import CalcModule

gen = ["male", "female"]
choices = ["software", "civil", "chemical", "electrical", "mechanical",  "materials", "engphys"]
testlst = [{"macid": 400158850, "fname": "Peter", "lname": "The Best", "gender": "male", "gpa": 12, "choice": [choices[0], choices[1], choices[2]]}]
male_gpa = 12
male_num = 1
female_gpa = 0
female_num = 0

for i in range(1, 1000):
    random.shuffle(choices)
    prev_gpa = testlst[i-1].get("gpa")
    if prev_gpa is not None:
        prev_gpa = float(prev_gpa)
        newstd = {"macid": 400158850+i, "fname": "liz("+str(i)+")", "lname": "goodman("+str(i)+")", "gender": gen[random.randint(0,1)], "gpa": (random.random()/500+0.998)*prev_gpa, "choice": [choices[0], choices[1], choices[2]]}
        g = newstd.get("gender")
        gp = newstd.get("gpa")
        if g is not None and gp is not None:
            if g == "male":
                male_gpa += gp
                male_num += 1
            else:
                female_gpa += gp
                female_num += 1
        testlst.append(newstd)

male_gpa /= male_num
female_gpa /= female_num

newlst = testlst
random.shuffle(newlst)
CalcModule.sort(newlst)
if newlst != testlst:
    print("error in sorting")
else:
    print("sorting is good")

random.shuffle(newlst)
print("male average gpa is ", male_gpa)
print("calculated male agpa is ", CalcModule.average(newlst, "male"))
print("female average gpa is ", female_gpa)
print("calculated female agpa is ", CalcModule.average(newlst, "female"))

capacity = {"software": 150, "civil": 150, "chemical": 150, "electrical": 150, "mechanical": 150,  "materials": 150, "engphys": 150}
free_choice = [400159849]
res = CalcModule.allocate(newlst, free_choice, capacity)
fc = 0
now = 0
for i in res:
    for j in range(i):
        if i[j].get("macid") == 400159849:
            fc += 1
            if (j != 0):
                print("error")
            continue
        if now > i[j]:
            print("error")
        else:
            now = i[j]
    if len(i) > 150:
        print("error")
    now = 0
