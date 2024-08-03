//
//  JumpGameII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#include "JumpGameII.hpp"
#include <algorithm>

int JumpGameII::jump(std::vector<int>& nums) {
    int numOfStep = 0;
    int l = 0, r = 0;
    
    while (r < nums.size()) {
        int maxStride = r+1;
        for (int i = l; i <= r; i++) {
            maxStride = std::max(maxStride, i+nums[i]);
        }
        l = r+1;
        r = maxStride;
        numOfStep++;
        if (maxStride >= nums.size()-1) return numOfStep;
    }
    return -1;
}
