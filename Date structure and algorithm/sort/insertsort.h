#ifndef _INSERTSORT_H
#define _INSERTSORT_H
#include<vector>
#include<algorithm>


template<typename T>
void insertsort(std::vector<T> &s )
{
    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j>=1&&s[j]<s[j-1];j-=1)
        {
            std::swap(s[j],s[j-1]);
        }
    }
}

#endif