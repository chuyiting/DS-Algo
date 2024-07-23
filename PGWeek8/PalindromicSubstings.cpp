//
//  PalindromicSubstings.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "PalindromicSubstings.hpp"

int countSubstringsCentreAt(std::string s, int c) {
    int sol = 0;
    int i = c, j = c;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        sol++;
        i--;
        j++;
    }
    i = c;
    j = c+1;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        sol++;
        i--;
        j++;
    }
    
    return sol;
}

int PalindromicSubstrings::countSubstrings(std::string s) {
    int sol = 0;
    for (int i = 0; i < s.size(); i++) {
        sol += countSubstringsCentreAt(s, i);
    }
    return sol;
}
