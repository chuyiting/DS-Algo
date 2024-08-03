//
//  DistinctSubsequences.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/23.
//

#include "DistinctSubsequences.hpp"
#include <vector>

int DistinctSubsequence::numDistinct(std::string s, std::string t) {
    if (t.size() > s.size()) return 0;
    std::vector<int> curr(t.size()+1, 0);
    std::vector<int> prev(t.size()+1, 0);
    prev[0] = 1;
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j < curr.size(); j++) {
            if (s[i] == t[j-1]) {
                curr[j] = prev[j] + prev[j-1];
            } else {
                curr[j] = prev[j-1];
            }
        }
        prev = curr;
    }
    
    return curr[t.size()];
}
