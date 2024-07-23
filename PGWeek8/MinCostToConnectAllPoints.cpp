//
//  MinCostToConnectAllPoints.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/1.
//

#include "MinCostToConnectAllPoints.hpp"
#include <queue>
#include <climits>
#include <unordered_set>
#include <algorithm>
#include <utility> 

struct MyComparator {
public:
    bool operator() (std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.first > p2.first;
    }
};

int distance(std::vector<int> p1, std::vector<int> p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int MinCostToConnectAllPoints::minCostConnectPoints (std::vector<std::vector<int>>& points) {
    int n = points.size();

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, MyComparator> q;
    q.push({0, 0});
    for (int i = 1; i < n; i++) {
        q.push({INT_MAX, i});
    }
    
    int sol = 0;
    std::unordered_set<int> visited;
    while (visited.size() < n && !q.empty()) {
        auto e = q.top();
        int key = e.first;
        int p = e.second;
        q.pop();
        if (visited.count(p) != 0) continue;
        
    
        sol += key;
        visited.insert(p);
        for (int i = 0; i < n; i++) {
            if (visited.count(i) == 1) continue;
            int newKey = distance(points[p], points[i]);
            q.push({newKey, i});
        }
    }
    return sol;
}
