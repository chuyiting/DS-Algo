//
//  NonOverlappingIntervals.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#include "NonOverlappingIntervals.hpp"
#include <algorithm>

bool doesOverlap(std::vector<int> i1, std::vector<int> i2) {
    bool noOverlap = i1[0] >= i2[1] || i1[1] <= i2[0];
    return !noOverlap;
}

int NonOverlappingIntervals::eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    int sol = 0;
    
    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> i1, std::vector<int> i2){return i1[1] < i2[1];});
    
    int currI = 0;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[currI][1]) {
            sol++;
        } else {
            currI = i;
        }
    }
    return sol;
}
