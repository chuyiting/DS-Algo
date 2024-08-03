//
//  RedundantConnection.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#ifndef RedundantConnection_hpp
#define RedundantConnection_hpp

#include <stdio.h>
#include <vector>

class RedundantConnection {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);
    std::vector<int> findRedundantConnectionUnionFind(std::vector<std::vector<int>>& edges);
    
    int find(std::vector<int> &parent, int e);
    void myunion(int x, int y, std::vector<int> &parent, std::vector<int> &rank);
};

#endif /* RedundantConnection_hpp */
