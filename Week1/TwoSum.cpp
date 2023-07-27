//
// Created by Eddy Chu on 2023/7/27.
//

#include "TwoSum.h"
#include <unordered_map>

std::vector<int> TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> visited; // key: value; val: index of the vector
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        auto diffId = visited.find(diff);
        if (diffId != visited.end()) {
            return {i, diffId->second};
        } else {
            visited.insert({nums[i], i});
        }
    }

    return std::vector<int>();
}
