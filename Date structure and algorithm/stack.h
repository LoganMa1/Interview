#ifndef _STACK_H_
#define _STACK_H_
#include"dequeue.h"


template<typename T>
class stack
{
private:
    dequeue<T> deque;
public:
    stack(){}
    ~stack(){}

    bool empty()const{return deque.empty();}
    int size()const{return deque.size();}
    T top()const{return deque.buttom();}
    void push_back(T item){deque.push_back(item);}
    void pop(){deque.pop_back();}
};

#endif