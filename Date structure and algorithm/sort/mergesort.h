#ifndef _MERGESORT_H
#define _MERGESORT_H
#include<vector>
#include<algorithm>


template<typename T>
class Sort {
    std::vector<T> tmp;
    void mergeSort(std::vector<T>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }
public:
    void sort(std::vector<T>& nums) {
        tmp.resize((int)nums.size(), (T)0);
        mergeSort(nums, 0, (int)nums.size() - 1);
    }
};

#endif