#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_


template<typename T>
class dequeue
{
private:
    class node
    {
    public:
        T item;
        node * pre;
        node * next;
        node(T t): item(t),pre(nullptr),next(nullptr){}
    };

    node * front;
    node * rear;
    int _length;
    dequeue(const dequeque<T & t){}
    dequeque<T>& operator=(const dequeue<T & t){}
public:
    dequeue():front(nullptr),rear(nullptr),_length(0){}
    ~dequeue();


    void push_back(T item);
    void push_front(T item);
    void pop_back();
    void pop_front();

    T front() const{return front->item;}
    T buttom() const{return rear->item;}

    bool empty() const{return _length==0;}
    int size() const{return _length;}

};


template<typename T>
dequeue<T>::~dequeue()
{
    while(front!=rear)
    {
        node * temp = front;
        front = front->next;
        delete(temp);
        _length--;
    }
}


template<typename T>
void dequeue<T>::push_back(T item)
{
    node * temp = new node(item);
    rear->next = temp;
    temp->pre = rear;
    rear = temp;
}


template<typename T>
void dequeue<T>::push_front(T item)
{
    node * temp = new node(item);
    front->pre = temp;
    temp->next = front;
    front = temp;
}


template<typename T>
void dequeue<T>::pop_back()
{
    node * temp = rear;
    rear = rear->pre;
    rear->next = nullptr;
    delete temp;
}


template<typename T>
void dequeue<T>::pop_front()
{
    node * temp = front;
    front = front->next;
    front->pre = nullptr;
    delete temp;
}


#endif