#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include<vector>

template<typename T>
int position(std::vector<T> & _arr, int _left, int _right)
{
    int i=_left,j = _right;
    T pivit = _arr[i];
    while(i<j)
    {
        while(i<j&&_arr[j]>pivit) j--;
        if(i<j) _arr[i++] = _arr[j];
        while(i<j&&_arr[i]<pivit) j++;
        if(i<j) _arr[j--] = _arr[i];
    }
    _arr[i] = pivit;
    return i;
}


template<typename T>
void quicksort(std::vector<T> & s, int l,int r )
{
    if(l>=r) return ; //
    int m = position(s,l,r);
    quicksort(s,l,m-1);
    quicksort(s,m+1,r);
}

#endif