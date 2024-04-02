//
//  PermutationInString.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/1.
//

#include "PermutationInString.hpp"
#include <unordered_map>

bool PermutationInString::checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> s1CharFreq;
    for (const auto& c:s1) {
        s1CharFreq[c]++;
    }
    
    int matchTarget = s1CharFreq.size();
    std::unordered_map<char, int> currFreq;
    int currMatch = 0;
    
    int l = 0;
    for (int r = 0; r < s2.size(); r++) {
        currFreq[s2[r]]++;
        if (currFreq[s2[r]] == s1CharFreq[s2[r]]) {
            currMatch++;
        }
        
        if (currMatch == matchTarget) {
            return true;
        }
        if (!s1CharFreq.count(s2[r])) {
            l = r+1;
            continue;
        }
        while (s1CharFreq[s2[r]] < currFreq[s2[r]]) {
            currFreq[s2[l]]--;
            if (currFreq[s2[l]] == s1CharFreq[s2[l]]-1)  {
                currMatch--;
            }
            l++;
        }
        
    }
    
    return false;
}
