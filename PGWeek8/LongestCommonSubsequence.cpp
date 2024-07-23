//
//  LongestCommonSubsequence.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/17.
//

#include "LongestCommonSubsequence.hpp"
#include <vector>
#include <algorithm>

int LongestCommonSubsequence::longestCommonSubsequence(std::string text1, std::string text2) {
    if (text1.size() > text2.size()) {
        std::string tmp = text1;
        text1 = text2;
        text2 = tmp;
    }
    
    std::vector<int> curr(text1.size()+1, 0);
    std::vector<int> prev(text1.size()+1, 0);
    
    for (int i = 0; i < text2.size(); i++){
        for (int j = 1; j < curr.size(); j++) {
            curr[j] = std::max(curr[j-1], prev[j]);
            if (text2[i] == text1[j-1]) {
                curr[j] = std::max(1+prev[j-1], curr[j]);
            }
        }
        prev = curr;
    }
    return curr[text1.size()];
}
