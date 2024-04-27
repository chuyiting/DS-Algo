//
//  PalindromePartitioning.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#include "PalindromePartitioning.hpp"

std::vector<std::vector<std::string>> PalindromePartitioning::partition(std::string s) {
    std::vector<std::string> curr;
    this->helper(s, curr, 0);
    return this->sol;
}

bool isPalindrome(std::string s) {
    for (int i = 0; i < s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

void PalindromePartitioning::helper(std::string s, std::vector<std::string> &curr, int id) {
    if (id >= s.size()) {
        this->sol.push_back(curr);
        return;
    }
    
    std::string str = "";
    for (int i = id; i < s.size(); i++) {
        str += std::string(1, s[i]);
        if (isPalindrome(str)) {
            curr.push_back(str);
            helper(s, curr, i+1);
            curr.pop_back();
        }
    }
    
}
