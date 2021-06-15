#include<unordered_map>
#include<list>
#include<vector>
#include<iterator>
#define MAXSIZE 10


namespace First
{
class LRU
{
private:
    struct Node
    {
        int key, val;
        Node(int _key=0,int _val=0):key(_key),val(_val){}
    };
    std::list<struct Node> lnode;

public:
    std::list<struct Node>::iterator find(int );
    void removeLast();
    void moveTofront(struct Node&);
    void put(int,int);
    int get(int);
};//class LRU


std::list<struct LRU::Node>::iterator LRU::find(int _key)
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


void LRU::moveTofront(struct Node & pnode)
{
    struct Node temp = pnode;
    lnode.remove(pnode);
    put(temp.key,temp.val);
}


void LRU::put(int key,int val)
{
    auto iter = find(key);
    if(iter!=lnode.end())
    {
        moveTofront(*iter);
        return ;
    }   
    if(lnode.size()>=MAXSIZE)
    {
        removeLast();
    }
    put(key,val);
}


int LRU::get(int _key)
{
    for(auto i = lnode.begin();i!=lnode.end();i++)
    {
        if(i->key==_key) return i->val;
    }
    return -1;
}

}//namespace


