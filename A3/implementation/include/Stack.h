/**
 * \file Stack.h
 * \author wengy12
 * \brief Stack
 */

#ifndef A3_STACK_H_
#define A3_STACK_H_

using namespace std;

template<class T>
class Stack{
private:
    vector <T> S;
public:
    /**
     * \brief void constructor
     */
    Stack();
    /**
     * \brief construct Stack from the vector
     */
    Stack(vector <T> v);
    /**
     * \brief push new element on top
     */
    Stack push (T x);
    /**
     * \brief delete the last element pushed
     */
    Stack pop ();
    /**
     * \brief get the top element
     */
    T top();
    /**
     * \brief get the size of stack
     */
    int size();
    /**
     * \brief return the stack as sequance (vector)
     */
    vector <T> toSeq();
    /**
     * \brief just made the oprrator to make life easier
     */
    T& operator [](int i){
        return this -> S[i];
    }
};

#endif
