//
//  LetterCombinationsOfAPhoneNumber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#include "LetterCombinationsOfAPhoneNumber.hpp"

std::vector<std::string> LetterCombinationsOfAPhoneNumber::letterCombinations(std::string digits) {
    if (digits == "") return {};
    std::string curr;
    this->helper(digits, 0, curr);
    return this->sol;
}

void LetterCombinationsOfAPhoneNumber::helper(std::string digits, int id, std::string &curr) {
    if (id >= digits.size()) {
        this->sol.push_back(curr);
        return;
    }
    
    auto candidates = this->digitCharMap[digits[id]];
    for (const auto & c : candidates) {
        curr += c;
        helper(digits, id+1, curr);
        curr = curr.substr(0, curr.size()-1);
    }
}
