#ifndef _SHELLSORT_H
#define _SHELLSORT_H
#include<vector>
#include<algorithm>

template<typename T>
void shellsort(std::vector<T> &s )
{
    int N = s.size();
    int h =1;
    while(h<N/3) h = h*3+1;
    while(h>=1)
    {
        for(int i=h;i<N;i++)
        {
            for(int j=i;j>=h&&s[j]<s[j-h];j-=h)
            {
                std::swap(s[j],s[j-h]);
            }
        }
        h = h/3;
    }
}
#endif