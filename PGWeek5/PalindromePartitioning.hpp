//
//  PalindromePartitioning.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef PalindromePartitioning_hpp
#define PalindromePartitioning_hpp

#include <stdio.h>
#include <string>
#include <vector>

class PalindromePartitioning {
    std::vector<std::vector<std::string>> sol;
public:
    std::vector<std::vector<std::string>> partition(std::string s);
    void helper(std::string s, std::vector<std::string> &curr, int id);
};

#endif /* PalindromePartitioning_hpp */
