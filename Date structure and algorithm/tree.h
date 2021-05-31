#ifndef _TREE_
#define _TREE_
#include<vector>

template<typename T>
struct Node
{
    T val;
    struct Node * left;
    struct Node * right;
    Node(T x):val(x),left(nullptr),right(nullptr) {}
};


template<typename T>
class Tree
{
private:
    struct Node * root;
public:
    Tree(): root{nullptr}{}
    Tree(const Tree<T> &);
    Tree<T> & operator=(const Tree<T> &);
    ~Tree();

    bool empty() const{return root==nullptr;}

    std::vector<T> preorder();
    std::vector<T> inorder();
    std::vector<T> postorder();

    std::vector<std::vector<T>> levelorder(); 
};

template<typename T>
Tree<T>::Tree(const Tree<T> & _tree)
{
    root = _tree.root;
    _tree.root = nullptr;
}


template<typename T>
Tree<T> & Tree<T>::operator=(const Tree<T> & _tree)
{
    if(this==&_tree)
    {
        return *this;
    }
    this->root = _tree;
    _tree.root  = nullptr;
    return *this;
}

#include <stack>
template<typename T>
std::vector<T> Tree<T>::preorder()
{
    std::vector<T> res;
    std::stack<struct Node *> stk;
    if(root = nullptr) return res;
    stk.push(root);
    while(!stk.empty())
    {
        struct Node * temp = stk.top();
        res.push_back(temp->val);
        stk.pop();
        if(temp->right) stk.push(temp->right);
        if(temp->left) stk.push(temp->left);
    }
    return res;
}


template<typename T>
std::vector<T> Tree<T>::inorder()
{
    std::vector<T> res;
    if(root==nullptr) return res;
    std::stack<struct Node *> stk;
    struct Node * p = root;
    while(!stk.empty()||p)
    {
        while(p)
        {
            stk.push(p);
            p = p->left;
        }
        struct Node * temp = stk.top();
        res.push_back(temp->val);
        stk.pop();
        p = p->right;
    }
    return res;
}


#include<algorithm>
template<typename T>
std::vector<T> Tree<T>::postorder()
{
    std::vector<T> res;
    if(root==nullptr) return res;
    std::stack<struct Node *> stk;
    stk.push(root);
    while(!stk.empty())
    {
        struct Node * temp  = stk.top();
        stk.pop();
        res.push_back(temp->val);
        if(temp->left) stk.push(temp->left);
        if(temp->right) stk.push(temp->right);
    }
    reverse(res.begin(),res.end());
    return res;
}


#include <queue>
template<typename T>
std::vector<std::vector<T>> Tree<T>::levelorder()
{
    std::vector<std::vector<T>> res;
    std::queue<struct Node *> que;
    if(root==nullptr) return res;
    que.push(root)
    while(!que.empty())
    {
        std::vector<T> temp;
        int count  = que.size();
        for(int i=0; i< count;i++)
        {
            temp.push(que.front());
            temp.pop();
        }
        res.push(temp);
    }
    return res;
}


template<typename T>
Tree<T>::~Tree()
{
    std::stack<struct Node *> stk;
    while(root||!stk.empty())
    {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        struct Node * temp = stk.top()
        stk.pop();
        delete 
    }
}

template<typename T>
Tree<T> createTreewithPI(const std::vector<T> & _p, const std::vector<T> & _i)
{
    
}
#endif