//
//  SurroundedRegions.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#ifndef SurroundedRegions_hpp
#define SurroundedRegions_hpp

#include <stdio.h>
#include <vector>

class SurroundedRegions {
    
public:
    void solve(std::vector<std::vector<char>>& board);
    void dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, int r, int c);
};

#endif /* SurroundedRegions_hpp */
