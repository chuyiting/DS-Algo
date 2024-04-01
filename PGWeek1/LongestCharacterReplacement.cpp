//
//  LongestCharacterReplacement.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/31.
//

#include "LongestCharacterReplacement.hpp"
#include <vector>

int LongestCharacterReplacement::characterReplacement(std::string s, int k) {
    std::vector<int> frequencyTable(26, 0);
    int l = 0;
    int sol = 0;
    for (int r = 0; r < s.size(); r++) {
        frequencyTable[s[r] - 'A']++;
        int maxF = 0;
        for (const auto&f : frequencyTable) {
            maxF = std::max(maxF, f);
        }
        
        if (r - l + 1  - maxF <= k) {
            sol = std::max(sol, r-l+1);
        } else {
            while (r - l + 1  - maxF > k) {
                frequencyTable[s[l] - 'A']--;
                l++;
                for (const auto&f : frequencyTable) {
                    maxF = std::max(maxF, f);
                }
            }
        }
    }
    
    return sol;
}

int LongestCharacterReplacement::characterReplacement2(std::string s, int k) {
    std::vector<int> frequencyTable(26, 0);
    int maxF = 0;
    int l = 0;
    int sol = 0;
    for (int r = 0; r < s.size(); r++) {
        frequencyTable[s[r] - 'A']++;
        maxF = std::max(maxF, frequencyTable[s[r] - 'A']);
        if (r-l+1 - maxF <= k) {
            sol = std::max(sol, r-l+1);
        } else {
            frequencyTable[s[l] - 'A']--;
            l++;
        }
        
    }
    
    return sol;
}
