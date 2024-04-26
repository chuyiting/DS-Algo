//
//  Permutations.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#ifndef Permutations_hpp
#define Permutations_hpp

#include <stdio.h>
#include <vector>

class Permutations {
    std::vector<std::vector<int>> sol;
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
    void permuteHelper(std::vector<int>& nums, std::vector<int>& curr, int start);
};

#endif /* Permutations_hpp */
