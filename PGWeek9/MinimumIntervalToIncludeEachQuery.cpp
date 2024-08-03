//
//  MinimumIntervalToIncludeEachQuery.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "MinimumIntervalToIncludeEachQuery.hpp"
#include <algorithm>
#include <queue>
#include <utility>

struct CandidateComparator{
public:
    bool operator()(std::pair<int, int> &c1, std::pair<int, int> &c2){
        return c1.first > c2.first;
    }
};

/*
 Unintuitive problem!!
 Practice more on the min/max heap problem
 */
std::vector<int> MinimumIntervalToIncludeEachQuery::minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
    std::vector<std::pair<int, int>> sortedq;
    // (query, id)
    for (int i = 0; i < queries.size(); i++) {
        sortedq.push_back({queries[i], i});
    }
    std::sort(sortedq.begin(), sortedq.end());
    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &i1, std::vector<int> &i2){return i1[0] < i2[0];});
    
    // (interval size, end point)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CandidateComparator> candidates;
    
    std::vector<int> sol(queries.size());
    int currI = 0;
    for (const auto &q : sortedq) {
        for (int i = currI; i < intervals.size(); i++) {
            if (q.first >= intervals[i][0] && q.first <= intervals[i][1]) {
                candidates.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                currI = i+1;
            } else if (q.first > intervals[i][1]){
                currI = i+1;
            } else {
                break;
            }
        }
        
        while (!candidates.empty() &&candidates.top().second < q.first) {
            candidates.pop();
        }
        
        if (candidates.empty()) {
            sol[q.second] =  -1;
        } else {
            sol[q.second] = candidates.top().first;
        }

    }
    return sol;
    
    
}
