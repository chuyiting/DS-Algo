//
//  RottingOranges.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#ifndef RottingOranges_hpp
#define RottingOranges_hpp

#include <stdio.h>
#include <vector>

class RottingOranges {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid);
    bool addIfCanBeRotted(std::vector<std::pair<int, int>>& rottenOranges, std::vector<std::vector<int>>& grid, int r, int c);
};

#endif /* RottingOranges_hpp */
