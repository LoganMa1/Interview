#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H
#include<vector>
#include<algorithm>


template<typename T>
int binary_search(const std::vector<T> & s, T target)
{
    int left = 0,right = s.size()-1;
    while(left<=right)
    {
        int mid = (right-left)>>1+left;
        if(s[mid]==target) return mid;
        else if(s[mid]>target) right = mid-1;
        else if(s[mid]<target) left = mid+1;
    }
    return -1;
}


template<typename T>
int left_bound(const std::vector<T> & s, T target)
{
    int left = 0,right = s.size()-1;
    while(left<=right)
    {
        int mid = (right-left)>>1+left;
        if(s[mid]==target) right = mid-1;
        else if(s[mid]>target) right = mid-1;
        else if(s[mid]<target) left = mid+1;
    }
    if(left>=s.size()||s[left]!=target)
        return -1;
    return left;
}


template<typename T>
int right_bound(const std::vector<T> &s, T target)
{
    int left = 0,right = s.size()-1;
    while(left<=right)
    {
        int mid = (right-left)>>1+left;
        if(s[mid]==target) left = mid+1;
        else if(s[mid]>target) right = mid-1;
        else if(s[mid]<target) left = mid+1;
    }
    if(right<0||s[right]!=target)
        return -1;
    return right;
}
#endif