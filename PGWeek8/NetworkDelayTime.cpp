//
//  NetworkDelayTime.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/6.
//

#include "NetworkDelayTime.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
#include <queue>
#include <utility>

struct PairComparator {
public:
    bool operator() (std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.first > p2.first;
    }
};

int NetworkDelayTime::networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::unordered_map<int ,std::vector<std::pair<int, int>>> graph;
    for (const auto &time : times) {
        if (graph.count(time[0]) == 0) {
            graph[time[0]] = {{time[1], time[2]}};
        } else {
            graph[time[0]].push_back({time[1], time[2]});
        }
    }
    
    std::vector<int> distance(n, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairComparator> q;
    for (int i = 1; i <= n; i++) {
        if (i == k) {
            distance[i] = 0;
            q.push({0, i});
        } else {
            distance[i] = INT_MAX;
        }
    }
    
    int sol = INT_MIN;
    std::unordered_set<int> visited;
    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        
        int v = e.second;
        int d = e.first;
        if (visited.count(v) != 0) continue;
        
        visited.insert(v);
        sol = std::max(sol, d);
        for (const auto &n : graph[v]) {
            if (d + n.second < distance[n.first]) {
                distance[n.first] = d + n.second;
                q.push({distance[n.first], n.first});
            }
        }
    }
    
    if (visited.size() < n) {
        return -1;
    }
    return sol;
    
}
