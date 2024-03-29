//
//  MaximumProductSubarray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/16.
//

#include "MaximumProductSubarray.hpp"

int MaximumProductSubarray::maxProduct(std::vector<int>& nums) {
    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int sol = maxSoFar;
    for (int i = 1; i < nums.size(); i++) {
        int maxSoFarTemp = maxSoFar;
        maxSoFar = std::max(std::max(maxSoFar*nums[i], minSoFar*nums[i]), nums[i]);
        minSoFar = std::min(std::min(maxSoFarTemp*nums[i], minSoFar*nums[i]), nums[i]);
        sol = std::max(maxSoFar, sol);
    }
    return sol;
}
