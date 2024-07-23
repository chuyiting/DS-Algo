//
//  PartitionEqualSubsetSum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/16.
//

#include "PartitionEqualSubsetSum.hpp"
#include <unordered_set>

bool PartitionEqualSubsetSum::canPartition(std::vector<int>& nums) {
    int sum = 0;
    for (auto &num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) return false;
    int half = sum / 2;
    
    std::vector<std::vector<bool>> validSum(half+1, std::vector<bool>(nums.size(), false));
    for (int i = 0; i < nums.size(); i++) {
        validSum[0][i] = true;
    }
    if (nums[0] == half) return true;
    

    for (int i = 1; i < validSum.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i - nums[j] >= 0) {
                validSum[i][j] = validSum[i - nums[j]][j-1] || validSum[i][j-1];
            }
            if (i == validSum.size()-1 && validSum[i][j] ) return true;
        }
    }
    return false;
}

bool PartitionEqualSubsetSum::canPartition2(std::vector<int>& nums) {
    int sum = 0;
    for (auto &num :nums) {
        sum += num;
    }
    
    if  (sum % 2 != 0) return false;
    int half = sum / 2;
    
    std::unordered_set<int> validSums;
    validSums.insert(0);
    if (nums[0] == half) return true;
    for (int i = 0; i < nums.size(); i++) {
        std::unordered_set<int> currSum;
        for (auto &vsum : validSums) {
            currSum.insert(nums[i] + vsum);
            if (nums[i] + vsum == half) return true;
        }
        validSums.insert(currSum.begin(), currSum.end());
    }
    return false;
    
}

bool PartitionEqualSubsetSum::canPartition3(std::vector<int>& nums) {
    int sum = 0;
    for (auto &num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) return false;
    int half = sum / 2;
    std::vector<bool> curr(half+1, false);
    std::vector<bool> prev(half+1, false);
    
    curr[0] = true;
    prev[0] = true;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < prev.size(); j++) {
            curr[j] = prev[j];
            if (j - nums[i] >= 0) {
                curr[j] = curr[j] || prev[j - nums[i]];;
            }
            prev = curr;
        }
        if (curr[half]) return true;
    }
    return false;
    
}
