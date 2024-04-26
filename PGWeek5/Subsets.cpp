//
//  Subsets.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#include "Subsets.hpp"

std::vector<std::vector<int>> Subsets::subsets(std::vector<int>& nums) {
    return this->subsetsFrom(nums, 0);
}
std::vector<std::vector<int>> Subsets::subsetsFrom(std::vector<int>& nums, int id) {
    if (id == nums.size()) {
        return {{}};
    }
    
    std::vector<std::vector<int>> subSubsets = subsetsFrom(nums, id+1);
    int n = subSubsets.size();
    for (int i = 0; i < n; i++) {
        std::vector<int> subsetCpy(subSubsets[i]);
        subsetCpy.push_back(nums[id]);
        subSubsets.push_back(subsetCpy);
    }
    return subSubsets;
}
