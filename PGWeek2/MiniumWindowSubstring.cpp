//
//  MiniumWindowSubstring.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/1.
//

#include "MiniumWindowSubstring.hpp"
#include <unordered_map>


std::string MinimumWindowSubstring::minWindow(std::string s, std::string t) {
    if (s.size() < t.size()) return "";
        
    std::unordered_map<char, int> charFreqForT;
    std::unordered_map<char, int> currFreq;
    
    for (const auto& c : t) {
        charFreqForT[c]++;
    }
    
    int targetMatch = charFreqForT.size();
    int currMatch = 0;
    int solL = INT_MAX;
    int solBegin = 0;
    
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
        currFreq[s[r]]++;
        if (currFreq[s[r]] == charFreqForT[s[r]]) currMatch++;
        
        while (currMatch == targetMatch) {
            if (r - l + 1 < solL) {
                solL = r-l+1;
                solBegin = l;
            }
            
            if (charFreqForT.count(s[l]) && currFreq[s[l]] == charFreqForT[s[l]]) {
                currMatch--;
            }
            currFreq[s[l]]--;
            l++;
        }
    }
    
    if (solL == INT_MAX) return "";
    return s.substr(solBegin, solL);
}
