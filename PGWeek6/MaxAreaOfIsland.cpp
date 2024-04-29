//
//  MaxAreaOfIsland.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#include "MaxAreaOfIsland.hpp"
#include <algorithm>

int MaxAreaOfIsland::maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    this->visited = std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false));
    int sol = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                sol = std::max(sol, getArea(i, j, grid));
            }
        }
    }
    return sol;
}

int MaxAreaOfIsland::getArea(int r, int c, std::vector<std::vector<int>>& grid) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    grid[r][c] = 0;
    return 1 + getArea(r+1, c, grid) + getArea(r-1, c, grid) + getArea(r, c+1, grid) + getArea(r, c-1, grid);
}
