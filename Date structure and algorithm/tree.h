#ifndef _TREE_
#define _TREE_


struct Node
{
    int val;
    struct Node * left;
    struct Node * right;
    Node(int x=0):val(x),left(nullptr),right(nullptr) {}
};


class Tree
{
private:
    struct Node * root;
public:
    Tree(): root{nullptr}{}
    Tree(const Tree &);
    Tree & operator=(const Tree &);
    ~Tree();
};

#endif