//
//  Permutations.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#include "Permutations.hpp"
#include <algorithm>

std::vector<std::vector<int>> Permutations::permute(std::vector<int>& nums) {
    std::vector<int> curr;
    permuteHelper(nums, curr, 0);
    return this->sol;
}

void Permutations::permuteHelper(std::vector<int>& nums, std::vector<int>& curr, int start) {
    if (start >= nums.size()) {
        this->sol.push_back(curr);
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        std::swap(nums[start], nums[i]);
        permuteHelper(nums, curr, start+1);
        std::swap(nums[start], nums[i]);
        curr.pop_back();
    }
    
}
