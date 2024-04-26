//
//  Subsets.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#ifndef Subsets_hpp
#define Subsets_hpp

#include <stdio.h>
#include <vector>

class Subsets {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums);
    std::vector<std::vector<int>> subsetsFrom(std::vector<int>& nums, int id);
};

#endif /* Subsets_hpp */
