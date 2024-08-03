//
//  BurstBalloons.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/23.
//

#include "BurstBalloons.hpp"
#include <algorithm>

/*
 max coin you can get from bursting balloon from subarray (i, j)
 = max_k maxCoin(i, k-1) + maxCoin(k+1, j) + nums[k] * nums[i-1] * nums[j+1]
 Base case: i == j maxCoin(i, i) = nums[i] * nums[i-1] * numss[i+1]
 Difficult Problem
 */

int getCoin(std::vector<int>& nums, int i) {
    if (i < 0 || i >= nums.size()) {
        return 1;
    }
    return nums[i];
}

int BurstBalloons::maxCoins(std::vector<int>& nums) {
    std::vector<std::vector<int>> coins(nums.size(), std::vector<int>(nums.size(), 0));
    
    for (int i = 0; i < nums.size(); i++) {
        coins[i][i] = getCoin(nums, i-1) * getCoin(nums, i) * getCoin(nums, i+1);
    }
    
    for (int size = 2; size <= nums.size(); size++){
        for (int i = 0; i + size - 1 < nums.size(); i++) {
            int j = i + size - 1;
            for (int k = i; k <= j; k++) {
                int first = k-1 >= 0 ? coins[i][k-1]: 0;
                int second = k+1 < nums.size() ? coins[k+1][j] : 0;
                coins[i][j] = std::max(first + second+ getCoin(nums, i-1) * getCoin(nums, k) * getCoin(nums, j+1), coins[i][j]);
            }
        }
    }
    return coins[0][nums.size()-1];
}
