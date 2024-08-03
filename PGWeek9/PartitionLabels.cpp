//
//  PartitionLabels.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#include "PartitionLabels.hpp"
#include <unordered_map>
#include <algorithm>


std::vector<int> PartitionLabels::partitionLabels(std::string s) {
    std::unordered_map<char, std::vector<int>> intervals;
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (intervals.count(c) == 0) {
            intervals[c] = {i, i};
        } else {
            intervals[c][1] = i;
        }
    }
    
    int end = intervals[s[0]][1];
    std::vector<int> sol;
    int size = 0;
    for (int i = 0; i < s.size(); i++) {
        end = std::max(end, intervals[s[i]][1]);
        if (end == i) {
            sol.push_back(size+1);
            size = 0;
        } else {
            size++;
        }
    }
    return sol;
}
