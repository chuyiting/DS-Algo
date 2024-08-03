//
//  MaximumSubarray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#include "MaximumSubarray.hpp"
#include <algorithm>

int MaximumSubarray::maxSubArray(std::vector<int>& nums) {
    int sol = nums[0];
    int curr = sol;
    for (int i = 1; i < nums.size(); i++) {
        curr = std::max(curr + nums[i], nums[i]);
        sol = std::max(curr, sol);
    }
    return sol;
}


int MaximumSubarray::maxSubArrayDivideAndConquer(std::vector<int>& nums) {
    return maxSubArrayDivideAndConquerHelper(nums, 0, nums.size()-1);
}

int MaximumSubarray::maxSubArrayDivideAndConquerHelper(std::vector<int>& nums, int i, int j) {
    if (i == j) return nums[i];
    if (i > j) return  0;
    int n = j-i+1;
    int m = n/2;
    
    int mid = i+m;
    int rightMax = nums[mid], currSum = rightMax;
    for (int it = mid+1; it <= j; it++) {
        currSum += nums[it];
        rightMax = std::max(rightMax, currSum);
    }
    currSum = 0;
    int leftMax = 0;
    for (int it = mid-1; it >=i; it--) {
        currSum += nums[it];
        leftMax = std::max(currSum, leftMax);
    }
    return std::max({leftMax+rightMax, maxSubArrayDivideAndConquerHelper(nums, i, mid),  maxSubArrayDivideAndConquerHelper(nums, mid+1, j)});
}
