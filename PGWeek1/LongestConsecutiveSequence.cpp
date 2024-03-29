//
//  LongestConsecutiveSequence.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/29.
//

#include "LongestConsecutiveSequence.hpp"
#include <unordered_set>

int LongestConsecutiveSequence::longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> visited;
    for (const auto& num:nums) {
        visited.insert(num);
    }
    
    int sol = 0;
    for (const auto& num:nums) {
        if (visited.count(num-1)) continue;
        int currLength = 0;
        int curr = num;
        while (visited.count(curr)) {
            currLength++;
            curr++;
        }
        sol = std::max(sol, currLength);
    }
    return sol;
    
}
