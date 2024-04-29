//
//  RottingOranges.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#include "RottingOranges.hpp"
#include <utility>

int RottingOranges::orangesRotting(std::vector<std::vector<int>>& grid) {
    std::vector<std::pair<int, int>> rottenOranges;
    int numOfOranges = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                rottenOranges.push_back({i, j});
                numOfOranges++;
            } else if (grid[i][j] == 1) {
                numOfOranges++;
            }
        }
    }
    
    bool moreOrangeRotting = true;
    int t = 0;
    while (moreOrangeRotting) {
        moreOrangeRotting = false;
        int n = rottenOranges.size();
        for (int i = 0; i < n; i++) {
            int r = rottenOranges[i].first, c = rottenOranges[i].second;
            if (addIfCanBeRotted(rottenOranges, grid, r+1, c)) {
                moreOrangeRotting = true;
            }
            if (addIfCanBeRotted(rottenOranges, grid, r-1, c)) {
                moreOrangeRotting = true;
            }
            if (addIfCanBeRotted(rottenOranges, grid, r, c+1)) {
                moreOrangeRotting = true;
            }
            if (addIfCanBeRotted(rottenOranges, grid, r, c-1)) {
                moreOrangeRotting = true;
            }
        }
        if (moreOrangeRotting) t++;
    }
    
    return rottenOranges.size() == numOfOranges ? t : 0;
}


bool RottingOranges::addIfCanBeRotted(std::vector<std::pair<int, int>>& rottenOranges, std::vector<std::vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1) return false;
    
    rottenOranges.push_back({r, c});
    grid[r][c] = 2;
    return true;
}
