//
//  MaxAreaOfIsland.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#ifndef MaxAreaOfIsland_hpp
#define MaxAreaOfIsland_hpp

#include <stdio.h>
#include <vector>

class MaxAreaOfIsland {
    std::vector<std::vector<bool>> visited;
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);
    int getArea(int r, int c, std::vector<std::vector<int>>& grid);
};

#endif /* MaxAreaOfIsland_hpp */
