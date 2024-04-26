//
//  SubsetsII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#include "SubsetsII.hpp"
#include <algorithm>

std::vector<std::vector<int>> SubsetsII::subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> curr;
    subsetsWithDupHelper(nums, curr, 0);
    return this->sol;
}

void SubsetsII::subsetsWithDupHelper(std::vector<int>& nums, std::vector<int> &curr, int id) {
    if (id == nums.size()) {
        this->sol.push_back(curr);
        return;
    }
    
    curr.push_back(nums[id]);
    subsetsWithDupHelper(nums, curr, id+1);
    curr.pop_back();
    int nextId = id;
    while (nextId < nums.size() && nums[nextId] == nums[id]){
        nextId++;
    }
    
    subsetsWithDupHelper(nums, curr, nextId);
}
