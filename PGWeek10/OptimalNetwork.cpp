//
//  OptimalNetwork.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/10/3.
//

#include "OptimalNetwork.hpp"
#include <algorithm>

class UnionFind {
    std::vector<int> parent;
    std::vector<size_t> size;
    
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(0);
        }
    }
    
    int find(int curr) {
        int sol = curr;
        while (parent[sol] != sol) {
            sol = parent[sol];
        }
        return sol;
    }
    
    bool union_(int n1, int n2) {
        int p1 = this->find(n1);
        int p2 = this->find(n2);
        if (p1 == p2) {
            return false;
        }
        
        if (this->size[p1] > this->size[p2]) {
            this->parent[p2] = p1;
            this->size[p1] = this->size[p1] + this->size[p2];
        } else {
            this->parent[p1] = p2;
            this->size[p2] = this->size[p1] + this->size[p2];
        }
        return true;
    }
    
};

struct Edge {
    int from; // 0 index
    int to; // 0 index
    int weight;
    Edge(int from, int to, int weight) {
        this->from = from;
        this->weight = weight;
        this->to = to;
    }
    
    bool operator<(const Edge &another) const {
        if (this->weight < another.weight) {
            return true;
        } else {
            return false;
        }
    }
};

int OptimalNetwork::getMinMaxLatency(int gNodes, std::vector<int> &gFrom, std::vector<int> &gTo, std::vector<int> &gWeight, int k) {
    UnionFind uf(gNodes);
    std::vector<Edge> edges;
    for (int i = 0; i < gFrom.size(); i++) {
        edges.emplace_back(gFrom[i]-1, gTo[i]-1, gWeight[i]);
    }
    
    std::sort(edges.begin(), edges.end());
    
    int currLatency = 0;
    int currNumOfComponent = gNodes;
    for (int i = 0; i < edges.size(); i++) {
        if (currNumOfComponent <= k) {
            return currLatency;
        }
        
        bool hasMerge = uf.union_(edges[i].to, edges[i].from);
        currLatency = std::max(currLatency, edges[i].weight);
        if (hasMerge) currNumOfComponent--;
    }
    return -1; // impossible to reach here
    
}
