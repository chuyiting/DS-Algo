//
//  NumberOfIslands.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#ifndef NumberOfIslands_hpp
#define NumberOfIslands_hpp

#include <stdio.h>
#include <vector>

class NumberOfIslands {
    std::vector<std::vector<bool>> visited;
public:
    int numIslands(std::vector<std::vector<char>>& grid);
    void dfs(int r, int c, std::vector<std::vector<char>>& grid);
};

#endif /* NumberOfIslands_hpp */
