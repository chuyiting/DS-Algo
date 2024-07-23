//
//  LongestPalindromicSubstring.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "LongestPalindromicSubstring.hpp"

std::string longestPalindromeCentreAt(std::string s, int c) {
    // check odd size palindrome
    int i = c-1, j = c+1;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    std::string longestStr = s.substr(i+1, j-i-1);
    
    // check even size palindrome
    if (c < s.size()-1 && s[c] == s[c+1]) {
        i = c-1;
        j = c+2;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j-i-1 > longestStr.size()) {
            longestStr = s.substr(i+1, j-i-1);
        }
    }
    return longestStr;
    
}

std::string LongestPalindromicSubstring::longestPalindrome(std::string s) {
    std::string sol = "";
    for (int i = 0; i < s.size(); i++) {
        std::string lp = longestPalindromeCentreAt(s, i);
        if (lp.size() > sol.size()) {
            sol = lp;
        }
    }
    return sol;
}
