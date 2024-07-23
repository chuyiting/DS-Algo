//
//  HouseRobberII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "HouseRobberII.hpp"
#include <algorithm>

int HouseRobberII::rob(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int curr = std::max(nums[0], nums[1]);
    int prev = nums[0];
    for (int i = 2; i < nums.size()-1; i++) {
        int tmp = curr;
        curr = std::max(prev +  nums[i], curr);
        prev = tmp;
    }
    
    int curr2 = std::max(nums[nums.size()-1], nums[nums.size()-2]);
    int prev2 = nums[nums.size()-1];
    for (int j = nums.size() - 3; j >= 0; j--) {
        int tmp = curr2;
        curr2 = std::max(curr2, prev2 + nums[j]);
        prev2 = tmp;
    }
    return std::max(curr, curr2);
}
