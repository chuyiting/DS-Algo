//
//  ValidTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/11.
//

#include "ValidTree.hpp"
#include <stack>
#include <unordered_set>
#include <numeric>

int find(std::vector<int> &parent, int node) {
    while (parent[node] != node)
        node = parent[node];
    return node;
}

void unionByRank(std::vector<int> &parent, std::vector<int> &rank, int i, int j) {
    if (rank[i] < rank[j]) {
        parent[i] = j;
    } else if (rank[i] > rank[j]) {
        parent[j] = i;
    } else {
        parent[i] = j;
        rank[j]++;
    }
}

bool ValidTree::validTree(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);
    std::vector<int> rank(n, 1);
    
    int numOfComponent = n;
    for (const auto &edge: edges) {
        int ip = find(parent, edge[0]);
        int jp = find(parent, edge[1]);
        if (ip == jp) return false;
        
        unionByRank(parent, rank, ip, jp);
        numOfComponent--;
    }
    return numOfComponent == 1;
    
}
