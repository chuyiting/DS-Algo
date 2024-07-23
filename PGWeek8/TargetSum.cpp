//
//  TargetSum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/19.
//

#include "TargetSum.hpp"

int TargetSum::findTargetSumWays(std::vector<int>& nums, int target) {
    int sum = 0;
    for (auto &num : nums) sum += num;
    std::vector<int> curr(sum*2+1, 0);
    std::vector<int> prev(sum*2+1, 0);
    curr[sum] = 1;
    prev[sum] = 1;
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < curr.size(); j++) {
            if (j - nums[i] >= 0) {
                curr[j] = prev[j-nums[i]];
            }
            
            if (j + nums[i] < curr.size()) {
                curr[j] += prev[j+nums[i]];
            }
        }
        prev = curr;
    }
    
    return curr[target + sum];
}
