//
//  KthLargestElementInAnArray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/23.
//

#include "KthLargestElementInAnArray.hpp"
#include <queue>
#include <functional>
#include <algorithm>


int KthLargestElementInAnArray::findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (const auto& num:nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int KthLargestElementInAnArray::findKthLargestQuickSelect(std::vector<int>& nums, int k) {
    return this->quickSelect(nums, nums.size()-k);
}

int KthLargestElementInAnArray::quickSelect(std::vector<int>& nums, int kthSmallest) {
    int l = 0, r = nums.size()-1;
    
    while (l <= r) {
        int p = this->partition(nums, l, r);
        if (p == kthSmallest) {
            return nums[p];
        } else if (p > kthSmallest){
            l = p+1;
        } else {
            r = p-1;
        }
    }
    
    return -1;
}

int KthLargestElementInAnArray::partition(std::vector<int>& nums, int begin, int end) {
    if (begin == end) return begin;
    int pivot = nums[end];
    int p = begin;
    
    for (int i = begin; i < end; i++) {
        if (nums[i] <= pivot) {
            std::swap(nums[i], nums[p]);
            p++;
        }
    }
    std::swap(nums[p], nums[end]);
    return p;
}
