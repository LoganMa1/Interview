#ifndef _SMART_PTR_
#define _SMART_PTR_

//share_ptr
template <typename T>
class MyShare_ptr
{
private:
    T * ptr;
    int * use_count;
public:
    MyShare_ptr(T *);
    MyShare_ptr(const MyShare_ptr<T>&);
    MyShare_ptr<T> & operator =(const MyShare_ptr &);
    ~MyShare_ptr();


    T operator *();
    T * operator ->();
    int GetCount() const{return *use_count;}


};

template<typename T>
MyShare_ptr<T>::MyShare_ptr(T * _p)
{
    ptr = _p;
    use_count = new int (1);
}


template<typename T>
MyShare_ptr<T>::MyShare_ptr(const MyShare_ptr<T> & share_ptr)
{
    ptr = share_ptr.ptr;
    use_count = share_ptr.use_count;
    (*use_count)++;
}


template<typename T>
MyShare_ptr<T> & MyShare_ptr<T>::operator =(const MyShare_ptr<T> & share_ptr)
{
    (*share_ptr.use_count)++;
    this->use_count--;
    if(this->use_count==0)
    {
        //call the T's destructor 
        delete ptr;
        ptr = nullptr;
        delete use_count;
        use_count = nullptr;
    }
    this->ptr = share_ptr.ptr;
    this->use_count = share_ptr.use_count;
    return *this;
}


template<typename T>
MyShare_ptr<T>::~MyShare_ptr()
{
    int count = --*(use_count);
    if(count<=0)
    {
        delete ptr;
        ptr = nullptr;
        delete use_count;
        use_count = nullptr;
    }
}


template<typename T>
T MyShare_ptr<T>::operator*()
{
    return * ptr;
}


template<typename T>
T * MyShare_ptr<T>::operator->()
{
    return ptr;
}

//unique_ptr
//#include<boost/noncopyable.hpp>
// template<typename T>
// class MyUnique_ptr
// {
// private:
//     T * ptr;
//     MyUnique_ptr(const MyUnique_ptr<T> & ){}
//     MyUnique_ptr<T> & operator=(const MyUnique_ptr<T> &){}
// public:
//     MyUnique_ptr(const T *);
//     MyUnique_ptr():ptr(nullptr){}
//     ~MyUnique_ptr();

//     T operator *();
//     T * operator ->();
//     friend MyUnique_ptr<T> move(MyUnique_ptr<T> & unique_ptr);
// };

// template<typename T>
// MyUnique_ptr<T>::MyUnique_ptr(const T * _ptr)
// {
//     ptr = _ptr;
// }


// template<typename T>
// MyUnique_ptr<T>::~MyUnique_ptr()
// {
//     delete ptr;
// }


// template<typename T>
// MyUnique_ptr<T> move(MyUnique_ptr<T> & unique_ptr)
// {
//     MyUnique_ptr<T> * res = new MyUnique_ptr<T>();
//     res->ptr = unique_ptr.ptr;
//     unique_ptr.ptr = nullptr;
//     return * res;
// }


// template<typename T>
// T MyUnique_ptr<T>:: operator *()
// {
//     return *ptr;
// }


// template<typename T>
// T * MyUnique_ptr<T>::operator->()
// {
//     return ptr;
// }
#endif