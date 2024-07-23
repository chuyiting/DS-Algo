//
//  HouseRobber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "HouseRobber.hpp"
#include <algorithm>

int HouseRobber::rob(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int prev = nums[0];
    int curr = std::max(nums[1], nums[0]);
    for (int i = 2; i < nums.size(); i++) {
        int tmp = curr;
        curr = std::max(curr, prev + nums[i]);
        prev = tmp;
    }
    return curr;
}
