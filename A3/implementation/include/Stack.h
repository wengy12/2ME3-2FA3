#ifndef A3_STACK_H_
#define A3_STACK_H_

using namespace std;

template<class T>
class Stack{
private:
    vector <T> S;
public:
    Stack();
    Stack(vector <T> v);
    Stack push (T x);
    Stack pop ();
    T top();
    int size();
    vector <T> toSeq();
    T& operator [](int i){
        return this -> S[i];
    }
};

#endif
