//
//  JumpGame.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#include "JumpGame.hpp"

bool JumpGame::canJump(std::vector<int>& nums) {
    std::vector<bool> canReachEnd(nums.size(), false);
    canReachEnd[nums.size()-1] = true;
    
    for (int i = nums.size()-2; i >= 0; i--) {
        for (int j = 1; j <= nums[i]; j++) {
            if (i+j < nums.size() && canReachEnd[i+j]) {
                canReachEnd[i] = true;
                break;
            }
        }
    }
    return canReachEnd[0];
}


bool JumpGame::canJumpGreedy(std::vector<int>& nums) {
    int goal = nums.size()-1;
    
    for (int i = nums.size()-2; i >= 0; i--) {
        if (nums[i] + i >= goal) {
            goal = i;
        }
    }
    return goal == 0;
}
