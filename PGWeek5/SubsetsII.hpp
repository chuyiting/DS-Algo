//
//  SubsetsII.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#ifndef SubsetsII_hpp
#define SubsetsII_hpp

#include <stdio.h>
#include <vector>

class SubsetsII {
    std::vector<std::vector<int>> sol;
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
    void subsetsWithDupHelper(std::vector<int>& nums, std::vector<int> &curr, int id);
};

#endif /* SubsetsII_hpp */
