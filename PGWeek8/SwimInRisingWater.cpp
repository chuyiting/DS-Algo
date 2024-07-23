//
//  SwimInRisingWater.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/6.
//

#include "SwimInRisingWater.hpp"
#include <utility>
#include <queue>
#include <climits>

int rcToId(int r, int c, int n){
    return r*n + c;
}

std::pair<int, int> idToRc(int id, int n) {
    int r = id / n;
    int c = id % n;
    return {r, c};
}

int SwimInRisingWater::swimInWater1(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    
    std::vector<int> distance(n * n, INT_MAX);
    distance[0] = grid[0][0];
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({grid[0][0], 0});
    
    std::vector<std::pair<int, int>> neighbor{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()){
        auto e = q.top();
        q.pop();
        int v = e.second;
        int d = e.first;
        if (d > distance[v]) continue;
        if (v == n*n-1) return d;
        
        auto point = idToRc(v, n);
        int r = point.first;
        int c = point.second;
        for (const auto &nei : neighbor) {
            int rp = r + nei.first;
            int cp = c + nei.second;
            if (rp >= 0 && rp < n && cp >= 0 && cp < n) {
                int newD = std::max(d, grid[rp][cp]);
                if (newD < distance[rcToId(rp, cp, n)]) {
                    distance[rcToId(rp, cp, n)] = newD;
                    q.push({newD, rcToId(rp, cp, n)});
                }
            }
        }
        
    }
    return -1;
}

int SwimInRisingWater::swimInWater2(std::vector<std::vector<int>>& grid) {
    
}
