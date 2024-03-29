//
//  ContainsDuplicate.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/29.
//

#include "ContainsDuplicate.hpp"
#include <unordered_set>

bool ContainsDuplicate::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> visited;
    for (const auto&num : nums) {
        if (visited.find(num) != visited.end()) return true;
        visited.insert(num);
    }
    return false;
};
