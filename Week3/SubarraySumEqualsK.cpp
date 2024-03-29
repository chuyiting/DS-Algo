//
//  SubarraySumEqualsK.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/6.
//

#include "SubarraySumEqualsK.hpp"
#include <unordered_map>

/**
 Naive solution: O(n^2)
 */
int SubarraySumEqualsK::subarraySum(std::vector<int>& nums, int k) {
    int sol = 0;
    for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
        int currSum = 0;
        for (int endIdx = startIdx; endIdx < nums.size(); endIdx++) {
            currSum += nums[endIdx];
            if (currSum == k) sol++;
        }
    }
    return sol;
}

/**
 Much greedier O(n)!! Prefix Sum Count Technique!!!
 */
int SubarraySumEqualsK::subarraySum2(std::vector<int>& nums, int k) {
    int sol = 0;
    std::unordered_map<int, int> prefixSumCount;
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        int residual = currSum - k;
        if (residual == 0) sol++;
        if (prefixSumCount.find(residual) != prefixSumCount.end()) {
            sol += prefixSumCount[residual];
        }
        
        prefixSumCount[currSum]++;
    }
    return sol;
}
