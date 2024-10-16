//
//  OptimalNetwork.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/10/3.
//

#ifndef OptimalNetwork_hpp
#define OptimalNetwork_hpp

#include <stdio.h>
#include <vector>

class OptimalNetwork {
public:
    int getMinMaxLatency(int gNodes, std::vector<int> &gFrom, std::vector<int> &gTo, std::vector<int> &gWeight, int k);
};

#endif /* OptimalNetwork_hpp */
