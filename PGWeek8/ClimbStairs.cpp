//
//  ClimbStairs.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "ClimbStairs.hpp"
#include <vector>

int ClimbStairs::climbStairsRecursive(int n) {
    if (n <= 0)  return 0;
    if (n == 1) return 1;
    return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);
}

int ClimbStairs::climbStairsDp(int n) {
    std::vector<int> ways(n+1);
    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2; i < ways.size(); i++) {
        ways[i] = ways[i-1] + ways[i-2];
    }
    return ways[n];
}

int ClimbStairs::climbStairsDpMem(int n) {
    int prev = 1, curr = 1;
    for (int i = 2; i < n+1; i++) {
        int tmp = curr;
        curr = curr + prev;
        prev = tmp;
    }
    return prev;
}
