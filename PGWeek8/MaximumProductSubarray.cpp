//
//  MaximumProductSubarray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "MaximumProductSubarray.hpp"
#include <climits>

int MaximumProductSubarray::maxProduct(std::vector<int>& nums) {
    double maxSoFar = nums[0], minSoFar = nums[0];
    double sol = maxSoFar;
    for (int i = 1; i < nums.size(); i++) {
        double maxTmp = maxSoFar, minTmp = minSoFar;
        double curr = double(nums[i]);
        maxSoFar = std::max({curr, maxSoFar * curr, minSoFar * curr});
        if (maxSoFar > sol)
            sol = maxSoFar;

        minSoFar = std::min({curr, maxTmp * curr, minTmp * nums[i]});
        
    }
    return sol;
}

