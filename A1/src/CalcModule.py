## @file CalcModule.py
#  @author janzej2
#  @brief Three functions for calculating/allocating students to their chosen programs.
#  @date 01/17/19

#import Read AllocationData as well as operator (used for sorting list of dictionaries)
import operator
from ReadAllocationData import *

## @brief This function sorts a list of dictionaries from lowest to highest GPAs
# @param S A list of students, each represented as a dictionary.
# @return A list of students, in order from highest to lowest GPAs.
#sort function inspired by https://www.geeksforgeeks.org/ways-sort-list-dictionaries-values-python-using-lambda-function/
def sort(S):
    return sorted(S, key = lambda i: i['gpa'], reverse=True)

## @brief This function finds the average GPA of a set of students (based on gender).
# @param L A list of dictionaries created by readStdnts(s).
# @param g A string representing the gender ("male" or "female").
# @return The average GPA of male or female students as a float.
def average(L, g):
    average = 0
    count = 0
    for i in range(len(L)):
        if L[i].get("gender") == g:
            count += 1
            average += L[i].get("gpa")
    if count != 0:
        return average/count
    else:
        return 0

## @brief This function allocates students to their program choices based on a number of
# factors.
# @details The function takes a list of all students, students with free choice and a
# dictionary containing the capacities of each department. If the student has free choice,
# they are automatically added to their chosen program (it is assumed that there will always
# be space in a given program for free choice students, see ReadAllocationData.py for full
# assumption list) while otherwise, they are allocated based on capacity.
# @param S A list of dictionaries of students, created by readStdnts().
# @param F A list of students with free choice (created by readFreeChoice()).
# @param C A dictionary of department capacities (created by readDeptCapacity()).
# @return A dictionary formatted with the format 'program' : [student, student...]
# for each potential program.
def allocate(S, F, C):
    civ, chem, elec, mech, soft, matls, engphys = ([] for i in range(7))
    #create final dictionary to return/index in the future
    final = {'civil' : civ, 'chemical' : chem, 'electrical' : elec, 'mechanical' : mech, 'software' : soft, 'materials' : matls, 'engphys' : engphys}
    #allocate free choice students first
    for i in range(len(F)):
        for j in range(len(S)):
            #find macid in student list and take index position
            if F[i] == S[j].get("macid"):
                break
        #add student to first choice program
        (final.get((S[j].get("choices"))[0])).append(S[i])
        #remove student from main student list so they aren't allocated twice
        del S[j]
    S = sort(S)
    #define previous GPA in case of duplicates
    previous = -1
    for i in range(len(S)):
        #only allocate those with gpa greater than 4.0. see assumptions in ReadAllocationData.py
        if S[i].get("gpa") < 4.0:
            break
        first = (S[i].get("choices"))[0]
        second = (S[i].get("choices"))[1]
        third = (S[i].get("choices"))[2]
        #check capacities and allocate accordingly
        if len(final.get(first)) < C.get(first) or (len(final.get(first)) == C.get(first) and previous == S[i].get('gpa')):
            (final.get(first)).append(S[i])
        elif len(final.get(second)) < C.get(second) or (len(final.get(second)) == C.get(second) and previous == S[i].get('gpa')):
            (final.get(second)).append(S[i])
        else:
            (final.get(third)).append(S[i])
        previous = S[i].get('gpa')
    return final
