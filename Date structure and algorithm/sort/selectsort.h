#ifndef _SELECTSORT_H
#define _SELECTOSRT_H
#include<vector>
#include<algorithm>

template<typename T>
void selectsort(std::vector<T> &s)
{
    int length = s.size()-1;
    for(int i=0;i<length;i++)
    {
        int min_pos = i;
        for(int j=i;j<=length;j++)
        {
            min_pos = s[min_pos]<s[j] ? min_pos:j;
        }
        std::swap(s[i],s[min_pos]);
    }
}

#endif