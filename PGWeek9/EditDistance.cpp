//
//  EditDistance.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/23.
//

#include "EditDistance.hpp"
#include <vector>
#include <algorithm>

int EditDistance::minDistance(std::string word1, std::string word2) {
    if (word1.size() > word2.size()) {
        std::string tmp = word1;
        word1 = word2;
        word2 = tmp;
    }
    
    std::vector<int> curr(word1.size()+1, 0);
    std::vector<int> prev(word1.size()+1, 0);
    
    for (int i = 0; i < prev.size(); i++) {
        prev[i] = i;
    }
    
    for (int i = 0; i < word2.size(); i++) {
        curr[0] = i+1;
        for (int j = 1; j < curr.size(); j++){
            if (word1[j-1] == word2[i]) {
                curr[j] = prev[j-1];
            } else {
                curr[j] = 1 + std::min({prev[j], curr[j-1], prev[j-1]});
            }
        }
        prev = curr;
    }
    return curr[curr.size()-1];
}
