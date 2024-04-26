//
//  CombinationSumII.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef CombinationSumII_hpp
#define CombinationSumII_hpp

#include <stdio.h>
#include <vector>

class CombinationSumII {
    std::vector<std::vector<int>> sol;
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
    
    void combinationSum2Helper(std::vector<int>& candidates, int id, std::vector<int>& curr, int target);
};
#endif /* CombinationSumII_hpp */
