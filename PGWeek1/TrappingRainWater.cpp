//
//  TrappingRainWater.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/30.
//

#include "TrappingRainWater.hpp"

// Time O(n) Space O(n)
int TrappingRainWater::trap(std::vector<int>& height) {
    std::vector<int> leftB(height.size(), 0), rightB(height.size(), 0);
    
    int n = height.size();
    for (int i = 1; i < height.size(); i++) {
        leftB[i] = std::max(height[i-1], leftB[i-1]);
        rightB[n-1-i] = std::max(height[n-i], rightB[n-i]);
    }
    
    int sol = 0;
    for (int i = 1; i < n-1; i++) {
        sol += std::max(0, std::min(rightB[i], leftB[i]) - height[i]);
    }
    
    return sol;
    
    
}

// Time O(n) Space O(1)
int TrappingRainWater::trap2(std::vector<int>& height) {
    auto l = height.begin(), r = height.end()-1;
    int maxL = *l, maxR = *r;
    int sol = 0;
    while (r > l) {
        if (maxL < maxR) {
            l++;
            sol += std::max(0, maxL - *l);
            maxL = std::max(maxL, *l);
        } else {
            r--;
            sol += std::max(0, maxR - *r);
            maxR = std::max(maxR, *r);
        }
    }
    return sol;
    
    
}
