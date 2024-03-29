//
//  FindMinimumInRotatedSortedArray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/27.
//

#include "FindMinimumInRotatedSortedArray.hpp"
#include <vector>

int FindMinimumInRotatedSortedArray::findMin(std::vector<int>& nums) {
    if (nums[0] <= nums[nums.size()-1]) {
        return nums[0];
    }
    
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (nums[mid] > nums[mid+1]) {
            return nums[mid+1];
        }
        
        // left side is sorted, min is on the right hand side
        if (nums[mid] > nums[l]) {
            l = mid;
        // right side is sorted
        } else {
            r = mid;
        }
    }
    
    return nums[0];
}
