//
//  RedundantConnection.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#include "RedundantConnection.hpp"
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>

std::vector<int> RedundantConnection::findRedundantConnection(std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, int> inDegrees;
    std::unordered_map<int, std::vector<int>> adjList;
    for (const auto &edge :edges) {
        inDegrees[edge[0]]++;
        inDegrees[edge[1]]++;
        if (adjList.count(edge[0]) == 0) {
            adjList[edge[0]] = {};
        }
        if (adjList.count(edge[1]) == 0) {
            adjList[edge[1]] = {};
        }
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    
    std::unordered_set<int> notInLoop;
    std::queue<int> q;
    for (const auto &p : inDegrees) {
        if (p.second == 1) {
            q.push(p.first);
        }
    }
    
    while (!q.empty()) {
        int neighbor = adjList[q.front()][0];
        for (auto it=adjList[neighbor].begin(); it != adjList[neighbor].end(); it++) {
            if (*it == q.front()) {
                adjList[neighbor].erase(it);
                break;
            }
        }
        notInLoop.insert(q.front());
        inDegrees[neighbor]--;
        if (inDegrees[neighbor] == 1) {
            q.push(neighbor);
        }
        q.pop();
    }
    
    for (int i = edges.size()-1; i >= 0; i--) {
        int v = edges[i][0];
        int u = edges[i][1];
        if (notInLoop.count(v) != 0 || notInLoop.count(u) != 0) {
            continue;
        }
        return edges[i];
    }
    
    return std::vector<int>();
}

std::vector<int> RedundantConnection::findRedundantConnectionUnionFind(std::vector<std::vector<int>>& edges) {
    std::vector<int> parent(edges.size()+1);
    std::vector<int> rank(edges.size()+1, 1);
    std::iota(parent.begin(), parent.end(), 0);
    
    for (const auto &e : edges) {
        int p0 = find(parent, e[0]);
        int p1 = find(parent, e[1]);
        if (p0 == p1) return e;
        if (rank[p1] < rank[p0]) {
            std::swap(p0, p1);
        }
        parent[p0] = p1;
        
    }
    return {};
}


int RedundantConnection::find(std::vector<int> &parent, int e) {
    if (parent[e] == e) return e;
    return find(parent, parent[e]);
}

