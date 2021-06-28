#include"quicksort.h"
#include"selectsort.h"
#include"insertsort.h"
#include"shellsort.h"
#include"mergesort.h"
#include"heapsort.h"
#include<vector>
#include<iostream>
#include<stdlib.h>

template<typename T>
void printarr(std::vector<T> & s)
{
    for(T i: s)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
void shuffle(std::vector<T> & s)
{
    int length = s.size()-1;
    for(int i=length;i>0;i--)
    {
        int ran = rand()%i;
        T temp = s[ran];
        s[ran] = s[i];
        s[i] = temp;
    }
}

int main()
{
    std::vector<int> s = {43,54,6,3,2,5,54,65,23};
    std::cout<<"Before sort:\n";
    printarr(s);

    quicksort(s,0,s.size()-1);

    std::cout<<"After quicksort sort:\n";
    printarr(s);

    shuffle(s);
    std::cout<<"After shuffle:\n";
    printarr(s);

    selectsort(s);
    std::cout<<"After select sort:\n";
    printarr(s);

    shuffle(s);
    std::cout<<"After shuffle:\n";
    printarr(s);

    insertsort(s);
    std::cout<<"After insert sort:\n";
    printarr(s);

    shuffle(s);
    std::cout<<"After shuffle:\n";
    printarr(s);

    shellsort(s);
    std::cout<<"After shell sort:\n";
    printarr(s);

    shuffle(s);
    std::cout<<"After shuffle:\n";
    printarr(s);

    Sort<int> * sort_p = new Sort<int>();
    sort_p->sort(s);
    std::cout<<"After merge sort:\n";
    printarr(s);

    shuffle(s);
    std::cout<<"After shuffle:\n";
    printarr(s);

    heapsort(s);
    std::cout<<"After heap sort:\n";
    printarr(s);
    return 0;
}