#ifndef _HEAPSORT_H
#define _HEAPSORT_H
#include<vector>
/* 
*the vector[0] also storage a data! 
*so the left child is i*2+1, the right child is i*2+2 
*/


template<typename T>
static void exchange(std::vector<T> & s, int k, int m)
{
    T temp = s[k];
    s[k] = s[m];
    s[m] = temp;
}


template<typename T>
static void sink(std::vector<T> & s, int k, int N)//N is the array max index.
{
    while(2*k+1<=N)
    {
        int child = 2*k+1;
        if(child<N&&s[child+1]>s[child]) child++;
        if(s[child]<s[k]) break;
        exchange(s,child,k);
        k = child;
    }
}

template<typename T>
static void swim(std::vector<T> & s, int k, int N)
{
    while(k/2>0)
    {
        int p = k/2;
        if(s[p]<s[k]) break;
        exchange(s,p,k);
        k = p;
    }
}


template<typename T>
void heapsort(std::vector<T> & s)
{
    int N = s.size();
    if(N<2) return;
    for(int i=N/2-1;i>=0;i--)
    {
        sink(s,i,N-1);
    }
    N--;
    while(N>0)
    {
        exchange(s,0,N--);
        sink(s,0,N);
    }
}
#endif