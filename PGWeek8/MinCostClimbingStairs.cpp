//
//  MinCostClimbingStairs.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "MinCostClimbingStairs.hpp"
#include <algorithm>

int MinCostClimbingStairs::minCostClimbingStairs(std::vector<int>& cost) {
    int curr = 0;
    int prev = 0;
    for (int i = 2; i <= cost.size(); i++) {
        int tmp = curr;
        curr = std::min(curr + cost[i-1], prev + cost[i-2]);
        prev = tmp;
    }
    return curr;
}
