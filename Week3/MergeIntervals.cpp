//
//  MergeIntervals.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/7.
//

#include "MergeIntervals.hpp"
#include <algorithm>

bool doesIntervalsOverlap(const std::vector<int>& i1, const std::vector<int>& i2) {
    if ((i1[0] > i2[1]) || i2[0] > i1[1]) return false;
    return true;
}

std::vector<int> mergeIntervals(const std::vector<int>& i1, const std::vector<int>& i2) {
    std::vector<int> result;
    result.push_back(std::min(i1[0], i2[0]));
    result.push_back(std::max(i1[1], i2[1]));
    return result;
}

std::vector<std::vector<int>> MergeIntervals::merge(std::vector<std::vector<int>>& intervals) {
    // sort intervals by the starting point of the interval
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
        return lhs[0] < rhs[0];
    });
    
    std::vector<std::vector<int>> ans;
    ans.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (doesIntervalsOverlap(ans[ans.size()-1], intervals[i])) {
            ans[ans.size()-1] = mergeIntervals(ans[ans.size()-1], intervals[i]);
        } else {
            ans.push_back(intervals[i]);
        }
    }
    
    return ans;
    
}
