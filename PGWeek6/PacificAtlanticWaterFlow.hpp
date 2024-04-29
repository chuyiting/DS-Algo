//
//  PacificAtlanticWaterFlow.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#ifndef PacificAtlanticWaterFlow_hpp
#define PacificAtlanticWaterFlow_hpp

#include <stdio.h>
#include <vector>

class PacificAtlanticWaterFlow {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);
    
    void flowUpward(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>> &visited, int r, int c, int prevHeight);
};

#endif /* PacificAtlanticWaterFlow_hpp */
