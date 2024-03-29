//
//  ContinuousSubarraySum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/7.
//

#include "ContinuousSubarraySum.hpp"
#include <unordered_map>

bool ContinuousSubarraySum::checkSubarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> residualAndEarliestIdx;
    int currSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        int residual = currSum % k;
        if (i >= 1 && residual == 0) return true;
        if (residualAndEarliestIdx.find(residual) != residualAndEarliestIdx.end()) {
            int earliestIdx = residualAndEarliestIdx[residual];
            if (i - earliestIdx >= 2) return true;
        } else {
            residualAndEarliestIdx[residual] = i;
        }
    }
    
    return false;
}
