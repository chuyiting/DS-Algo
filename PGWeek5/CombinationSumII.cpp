//
//  CombinationSumII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#include "CombinationSumII.hpp"
#include <algorithm>


std::vector<std::vector<int>> CombinationSumII::combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> curr;
    combinationSum2Helper(candidates, 0, curr, target);
    return this->sol;
}

void CombinationSumII::combinationSum2Helper(std::vector<int>& candidates, int id, std::vector<int>& curr, int target) {
    if (id >= candidates.size()) return;
    
    curr.push_back(candidates[id]);
    if (candidates[id] == target) {
        this->sol.push_back(curr);
    } else if (candidates[id] < target) {
        combinationSum2Helper(candidates, id+1, curr, target-candidates[id]);
    }
    
    curr.pop_back();
    
    if (candidates[id] < target) {
        int nextId = id;
        while (nextId < candidates.size() && candidates[nextId] == candidates[id]) {
            nextId++;
        }
        combinationSum2Helper(candidates, nextId, curr, target);
    }
    
}
