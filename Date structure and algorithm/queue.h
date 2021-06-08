#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"dequeue.h"


template<typename T>
class queue
{
private:
    dequeue<T> deque;
public:
    queue(){}
    ~queue(){}

    bool empty(){return deque.empty();}
    int size() const{return deque.size();}
    T front() const {return deque.front();}
    t back() const {return deque.buttom();}
    void push(T item){deque.push_back(item);}
    void pop(){deque.pop_front();}
};


#endif