//
//  ContainWithMostWater.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/27.
//

#include "ContainWithMostWater.hpp"

int ContainWithMostWater::maxArea(std::vector<int>& height) {
    int l = 0, r = height.size()-1;
    int m = 0;
    while (l != r) {
        m = std::max(m, (r-l) * std::min(height[l], height[r]));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    
    return m;
}
