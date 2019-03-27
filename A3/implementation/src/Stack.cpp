// Implementation here
#include <vector>
#include "Stack.h"
#include "CardTypes.h"
//#include <exeption>

using namespace std;



template <class T>
Stack <T> ::Stack(vector <T> v){
    this -> S = v;
}

template <class T>
Stack <T> ::Stack(){}

template <class T>
Stack <T> Stack <T>::push(T x){
    this -> S.push_back(x);
    Stack <T>* re = new Stack <T> (this -> S);
    this -> S.pop_back();
    return re[0];
}

template <class T>
Stack <T> Stack <T>::pop(){
    if (this -> S.size() == 0){
        throw out_of_range("pop");
    }
    Stack <T>* re = new Stack <T> (this -> S);
    re -> S.pop_back();
    //this -> S.pop_back();
    return re[0];
}

template <class T>
T Stack <T>::top(){
    if (this -> S.size() == 0){
        throw out_of_range("top1");
    }
    return this -> S[this -> S.size()-1];
}

template <class T>
int Stack <T>::size(){
    return this -> S.size();
}

template <class T>
vector <T> Stack <T>::toSeq(){
    return this -> S;
}



// Keep this at bottom
template class Stack<CardT>;
