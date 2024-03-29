//
//  SearchInRotatedSortedArray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/16.
//

#include "SearchInRotatedSortedArray.hpp"

int SearchInRotatedSortedArray::search(std::vector<int>& nums, int target) {
    if (nums.size() == 1) {
        return target == nums[0] ? 0 : -1;
    }
    
    int leftIdx = 0;
    int rightIdx = nums.size() - 1;
    
    int pivot = (rightIdx + leftIdx) / 2;
    while (true) {
        if (nums[pivot] > nums[pivot+1]) break;
        if (nums[pivot] < nums[leftIdx]) {
            rightIdx = pivot;
        } else {
            leftIdx = pivot;
        }
    }
    
    int rotation = pivot + 1;
    int l = 0;
    int r = nums.size()-1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        int idx = (mid + rotation) % nums.size();
        int t = nums[idx];
        if (t == target) {
            return idx;
        } else if (target < t) {
            r = mid;
        } else {
            l = (mid + 1) % nums.size();
        }
        
    }
    
    return -1;
}

int SearchInRotatedSortedArray::search2(std::vector<int>& nums, int target) {
    int leftIdx = 0, rightIdx = nums.size()-1;
    while (leftIdx <= rightIdx) {
        int midIdx = (leftIdx + rightIdx) / 2;
        if (target == nums[midIdx]) return midIdx;
        
        // left side is sorted
        if (nums[leftIdx] < nums[midIdx]) {
            // if target is in the range of the left sorted array
            if (nums[leftIdx] <= target && nums[midIdx] >= target) {
                rightIdx = (midIdx-1 + nums.size()) % nums.size();
            } else {
                leftIdx = (midIdx + 1) % nums.size();
            }
        } else {
            if (nums[midIdx] <= target && nums[rightIdx] >= target) {
                leftIdx = (midIdx + 1) % nums.size();
            } else {
                rightIdx = (midIdx-1 + nums.size()) % nums.size();
            }
        }
    }
    return -1;
}
