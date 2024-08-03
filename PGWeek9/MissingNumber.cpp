//
//  MissingNumber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "MissingNumber.hpp"

int MissingNumber::missingNumber(std::vector<int>& nums) {
    unsigned int visited = 0x0;
    for (const auto &num : nums) {
        visited = visited | (1 << num);
    }
    
    int sol = 0;
    while (visited) {
        if (!(visited & 1)) return sol;
        visited = visited >> 1;
        sol++;
    }
    return nums.size();
}
