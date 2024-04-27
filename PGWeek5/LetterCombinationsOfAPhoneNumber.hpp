//
//  LetterCombinationsOfAPhoneNumber.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef LetterCombinationsOfAPhoneNumber_hpp
#define LetterCombinationsOfAPhoneNumber_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

class LetterCombinationsOfAPhoneNumber {
    std::unordered_map<char, std::vector<char>> digitCharMap{{'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r','s'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    std::vector<std::string> sol;
public:
    std::vector<std::string> letterCombinations(std::string digits);
    void helper(std::string digits, int id, std::string &curr);
};

#endif /* LetterCombinationsOfAPhoneNumber_hpp */
