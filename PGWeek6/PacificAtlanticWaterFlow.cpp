//
//  PacificAtlanticWaterFlow.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#include "PacificAtlanticWaterFlow.hpp"

std::vector<std::vector<int>> PacificAtlanticWaterFlow::pacificAtlantic(std::vector<std::vector<int>>& heights) {
    std::vector<std::vector<bool>> pacific(heights.size(), std::vector<bool>(heights[0].size(), false));
    std::vector<std::vector<bool>> atlantic(heights.size(), std::vector<bool>(heights[0].size(), false));
    
    for (int i = 0; i < heights.size(); i++) {
        flowUpward(heights, pacific, i, 0, 0);
        flowUpward(heights, atlantic, i, heights[0].size()-1, 0);
    }
    
    for (int j = 0; j < heights[0].size(); j++) {
        flowUpward(heights, pacific, 0, i, 0);
        flowUpward(heights, atlantic, heights.size()-1, i, 0);
    }
    
    std::vector<std::vector<int>> sol;
    for (int r = 0; r < heights.size(); r++) {
        for (int c = 0; c < heights[0].size(); c++) {
            if (pacific[r][c] && atlantic[r][c]) {
                sol.push_back({r, c});
            }
        }
    }
    return sol;
    
}

void PacificAtlanticWaterFlow::flowUpward(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>> &visited, int r, int c, int prevHeight) {
    if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] || heights[r][c] < prevHeight) {
        return;
    }
    
    visited[r][c] = true;
    flowUpward(heights, visited, r+1, c, heights[r][c]);
    flowUpward(heights, visited, r-1, c, heights[r][c]);
    flowUpward(heights, visited, r, c+1, heights[r][c]);
    flowUpward(heights, visited, r, c-1, heights[r][c]);
}
