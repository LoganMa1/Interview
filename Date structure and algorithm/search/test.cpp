#include"binary_search.h"
#include<iostream>
#include<vector>
#include"../sort/quicksort.h"

template<typename T>
void printarr(const std::vector<T> & s)
{
    for(auto i: s)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}


int main()
{
    std::vector<int> arr = {43,53,32,68,68,68,56,54,53,78,43};
    int target = *arr.begin();

    quicksort(arr,0,arr.size()-1);
    std::cout<<"After sort:\n";
    printarr(arr);

    std::cout<<"the "<<target<<" at "<<binary_search(arr,target)<<"st!\n";
    std::cout<<"the left "<<target<<" at "<<left_bound(arr,target)<<"st!\n";
    std::cout<<"the right "<<target<<" at "<<right_bound(arr,target)<<"st!\n";

    return 0;
}