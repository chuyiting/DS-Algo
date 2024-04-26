//
//  CombinationSum.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#ifndef CombinationSum_hpp
#define CombinationSum_hpp

#include <stdio.h>
#include <vector>

class CombinationSum {
    std::vector<std::vector<int>> sol;
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
    
    void combinationSumHelper(std::vector<int>& candidates, std::vector<int>& curr, int id, int target);
};

#endif /* CombinationSum_hpp */
