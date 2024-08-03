//
//  SingleNumber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "SingleNumber.hpp"

int SingleNumber::singleNumber(std::vector<int>& nums) {
    int sol = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sol = sol ^ nums[i];
    }
    return sol;
}
