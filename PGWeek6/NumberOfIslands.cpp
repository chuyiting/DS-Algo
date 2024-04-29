//
//  NumberOfIslands.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#include "NumberOfIslands.hpp"

int NumberOfIslands::numIslands(std::vector<std::vector<char>>& grid) {
    this->visited = std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false));
    int sol = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                sol++;
                dfs(i, j, grid);
            }
        }
    }
    return sol;
}


void NumberOfIslands::dfs(int r, int c, std::vector<std::vector<char>>& grid) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0' || this->visited[r][c]) {
        return;
    }
    
    this->visited[r][c] = true;
    grid[r][c] = '0';
    dfs(r+1, c, grid);
    dfs(r-1, c, grid);
    dfs(r, c+1, grid);
    dfs(r, c-1, grid);
}
