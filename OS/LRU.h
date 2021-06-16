#include<unordered_map>
#include<list>
#include<vector>
#include<iterator>
#define MAXSIZE 10


namespace First
{
//put opterator:O(n)
//get opterator:O(n)
class LRU
{
private:
    struct Node
    {
        int key, val;
        Node(int _key=0,int _val=0):key(_key),val(_val){}
    };
    typedef std::list<struct Node> Nodelist;
    std::list<struct Node> lnode;
    int size;
    
    //some private help function
    Nodelist::iterator find(int );
    void removeLast();
    void moveTofront(Nodelist::iterator &);

public:
    LRU(int _size=MAXSIZE):size(_size){}
    void put(int,int);
    int get(int);
};//class LRU


LRU::Nodelist::iterator LRU::find(int _key)
{
    for(auto i = lnode.begin();i!=lnode.end();i++)
    {
        if(i->key==_key)return i;
    }
    return lnode.end();
}


void LRU::removeLast()
{
    if(lnode.size()>0)
    {
        lnode.pop_back();
    }
}


void LRU::moveTofront(Nodelist::iterator & _iter)
{
    int key = _iter->key;
    int val = _iter->val;
    lnode.remove(*_iter);
    put(key,val);
}


void LRU::put(int key,int val)
{
    auto iter = find(key);
    if(iter!=lnode.end())
    {
        moveTofront(iter);
        return ;
    }   
    if(lnode.size()>=size)
    {
        removeLast();
    }
    lnode.push_front(Node(key,val));
}


int LRU::get(int _key)
{
    auto iter = find(_key);
    if(iter!=lnode.end())
    {
        moveTofront(iter);
        return lnode.front().val;
    }
    return -1;
}
}//namespace


namespace Second
{
//put opterator:O(1)
//get opterator:O(1)
class LRU
{
    struct Node 
    {
        int key,val;
        Node(int _key = 0,int _val=0):key(_key),val(_val){}
        
    };
    typedef std::list<struct Node> Nodelist;
    std::unordered_map<int,Nodelist::iterator>hashmap;
    std::list<struct Node> lnode;
    int size;

    //private help function
    void remove(Nodelist::iterator &);
    void add(int,int);
public:
    LRU(int _size = MAXSIZE):size(_size){}
    void put(int,int);
    int get(int );
};


void LRU::remove(Nodelist::iterator & _iter)
{
    int key = _iter->key;
    int val = _iter->val;
    hashmap.erase(key);
    lnode.erase(_iter);
}

void LRU::add(int _key,int _val)
{
    lnode.push_front(Node(_key,_val));
    hashmap[_key] = lnode.begin();
    if(lnode.size()>size)
    {
        auto end = lnode.end();
        remove(--end);
    }
}


void LRU::put(int _key,int _val)
{
    auto iter = hashmap.find(_key);
    if(iter!=hashmap.end())
    {
        remove(iter->second);
    }
    add(_key,_val);
}


int LRU::get(int _key)
{
    auto iter = hashmap.find(_key);
    if(iter!=hashmap.end())
    {
        int temp = iter->second->val;
        remove(iter->second);
        add(_key,temp);
        return temp;
    }
    return -1;
}
}//namespace


