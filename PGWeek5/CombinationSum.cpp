//
//  CombinationSum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#include "CombinationSum.hpp"

std::vector<std::vector<int>> CombinationSum::combinationSum(std::vector<int>& candidates, int target) {
    std::vector<int> curr;
    combinationSumHelper(candidates, curr, 0, target);
    return this->sol;
}

void CombinationSum::combinationSumHelper(std::vector<int>& candidates, std::vector<int> &curr, int id, int target) {
    if (id >= candidates.size()) return;
    if (target == 0) {
        this->sol.push_back(curr);
        return;
    }
    
    int maxRe = target / candidates[id];
    for (int i = 0; i <= maxRe; i++) {
        for (int j = 0; j < i; j++) {
            curr.push_back(candidates[id]);
        }
        combinationSumHelper(candidates, curr, id+1, target-i*candidates[id]);
        for (int j = 0; j < i; j++) {
            curr.pop_back();
        }
    }
}
