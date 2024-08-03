//
//  InsertInterval.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#include "InsertInterval.hpp"

bool doesOverlap(std::vector<int> &i1, std::vector<int> &i2) {
    bool noOverlap = i1[1] < i2[0] || i1[0] > i2[1];
    return !noOverlap;
}

std::vector<std::vector<int>> InsertInterval::insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    
    std::vector<std::vector<int>> sol;
    bool used = false;
    
    for (int i = 0; i < intervals.size(); i++) {
        if (newInterval[1] < intervals[i][0]) {
            if (!used){
                sol.push_back(newInterval);
                used = true;
            }
            
            sol.push_back(intervals[i]);
        } else if (intervals[i][1] < newInterval[0]) {
            sol.push_back(intervals[i]);
        } else {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    
    if (sol.empty()) {
        sol.push_back(newInterval);
    } else if (sol[sol.size()-1][1] < newInterval[0]) {
        sol.push_back(newInterval);
    }
   
    return sol;
}
