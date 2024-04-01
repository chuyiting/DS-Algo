//
//  LongestSubstringWithoutRepeatingChar.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/31.
//

#include "LongestSubstringWithoutRepeatingChar.hpp"

#include <unordered_set>

int LongestSubstringWithoutRepeatingChar::lengthOfLongestSubstring(std::string s) {
    
    std::unordered_set<char> currCharSet;
    int sol = 0;
    
    int l = 0, r = 0;
    
    while (r < s.size()) {
        if (!currCharSet.count(s[r])) {
            currCharSet.insert(s[r]);
            sol = std::max(r-l+1, sol);
        } else {
            while (s[l] != s[r]) {
                currCharSet.erase(s[l]);
                l++;
            }
            l++;
        }
        
        r++;
    }
    
    return sol;
}
