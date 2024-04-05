//
//  BinarySearch.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/5.
//

#include "BinarySearch.hpp"

int BinarySearch::search(std::vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid+1;
        } else {
            r = mid-1;
        }
        
    }
    return -1;
}
