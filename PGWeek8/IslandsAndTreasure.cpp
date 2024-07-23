//
//  IslandsAndTreasure.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/11.
//

#include "IslandsAndTreasure.hpp"
#include <utility>
#include <climits>
#include <queue>

void IslandsAndTreasure::islandsAndTreasure(std::vector<std::vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::pair<int, int>> treasures;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                treasures.push_back({i, j});
            }
        }
    }
    
    std::vector<std::pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (const auto & treasure : treasures) {
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        
        
        std::queue<std::pair<int, int>> q;
        q.push(treasure);
        int dist = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                visited[r][c] = 1;
                if (grid[r][c] > dist) grid[r][c] = dist;
                
                for (const auto &neighbor : neighbors) {
                    int rn = r + neighbor.first;
                    int cn = c + neighbor.second;
                    if (rn < m && rn >= 0 && cn < n && cn >= 0 && !visited[rn][cn] && grid[rn][cn] > 0) {
                        q.push({rn, cn});
                    }
                }
            }
            dist++;
        }
        
    }
}


