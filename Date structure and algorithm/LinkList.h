#ifndef _LINKLIST_
#define _LINKLIST_
#include <iostream>

struct Node
{
    int val;
    struct Node * next;
    Node(int x=0):val(x),next(nullptr){}
};


class LinkList
{
private:
    struct Node *head;
    struct Node * tail;
    int _length;
public:
//Constructer, Copy , Assign
    LinkList():head(nullptr),tail(nullptr),_length(0) {}
    LinkList(const LinkList & );
    LinkList(int *, int );
    LinkList & operator=(const LinkList & );
    ~LinkList();


//Get Pointers
    struct Node * cbegin() const {return head;}
    struct Node * cend() const {return tail;}

//Capacity
    int size() const{return _length;}
    int length() const{return _length;}
    bool empty() {return head==tail;}

//Element access
    int operator [](int);
    int back() const {return head->val;}
    int front() const {return tail->val;}
    int at(int n);

//Modifiers
    LinkList & operator +=( const LinkList & );
    LinkList & operator +=(int);
    LinkList & append(int);
    void push_back(int);
    void insertHead(int);
    void insertTail(int);
    void pop_back();

//Other
    struct Node * find(int);
    friend std::ostream & operator <<(std::ostream &, const LinkList & );
};


inline LinkList::LinkList(const LinkList & linklist)
{   
    while(head!=tail)
    {
        delete head;
        head=head->next;
    }
    _length = linklist._length;
    struct Node * p = linklist.head;
    struct Node * dummy = new Node();
    struct Node * t = dummy;
    while(p!=linklist.tail)
    {
        struct Node * newNode = new Node(p->val);
        t->next = newNode;
        t = newNode;
        p = p->next;
    }
    head = new Node();head = dummy->next;
    tail = new Node();tail = t;
}


inline LinkList & LinkList::operator =(const LinkList & linklist)
{
    _length = linklist._length;
    if(head==linklist.head&&tail==linklist.tail)
    {
        return * this;
    }
    struct Node * p = linklist.head;
    struct Node * dummy = new Node();
    struct Node * t = dummy;
    while(p!=linklist.tail)
    {
        struct Node * newNode = new Node(p->val);
        t->next = newNode;
        t = newNode;
        p = p->next;
    }
    while(linklist.head!=linklist.tail)
    {
        delete head;
        head = head->next;
    }
    head = new Node();head = dummy->next;
    tail = new Node();tail = t;
    return *this;
}


inline LinkList::LinkList(int * arr, int n)
{
    for(int * p = arr; p<arr+n; p++)
    {   
        insertTail(*p);
    }
}


inline LinkList::~LinkList()
{
    while (head!=tail)
    {
        delete head;
        head=head->next;
    }
    delete tail;
    _length = 0;
}


inline int LinkList::operator [](int n)
{
    if(n>_length)
    {
        return -99999;
    }
    int i=0;
    struct Node * p = head;
    while(i<n)
    {
        p=p->next;
        i++;
    }
    return p->val;
}


inline int LinkList::at(int n)
{
    return (*this)[n];
}


inline LinkList & LinkList::operator +=( const LinkList & linklist)
{
    _length += linklist._length;
    tail->next = linklist.head;
    tail = linklist.tail;
    return *this;
}


inline LinkList & LinkList::operator +=(int n)
{
    insertTail(n);
    return *this;
}


inline LinkList & LinkList::append(int n)
{
    insertTail(n);
    return *this;
}


inline void LinkList::push_back(int n)
{
    insertTail(n);
}


inline void LinkList::insertHead(int n)
{
    _length++;
    struct Node * p = new Node(n);
    p->next = head;
    head = p;
}


inline void LinkList::insertTail(int n)
{
    _length++;
    struct Node * p = new Node(n);
    tail->next = p;
    tail = p;
}


inline void LinkList::pop_back()
{
    struct Node * p = head;
    while(p->next!=head)
    {
        p=p->next;
    }
    tail = p;
    delete p->next;
    p->next = nullptr;
}


inline struct Node * LinkList::find(int x)
{
    struct Node * p = head;
    while(p!=tail)
    {
        if(p->val==x) return p;
    }
    return tail;
}


std::ostream & operator <<(std::ostream & os, const LinkList & linklist)
{
    struct Node * p = linklist.head;
    while(p!=linklist.tail)
    {
        os<<p->val<<" ";
    }
    return os<<"\n";
}
#endif