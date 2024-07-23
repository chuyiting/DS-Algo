//
//  CheapestFlightsWithinKStops.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/6.
//

#ifndef CheapestFlightsWithinKStops_hpp
#define CheapestFlightsWithinKStops_hpp

#include <stdio.h>
#include <vector>

class CheapestFlightsWithinKStops{
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k);
};

#endif /* CheapestFlightsWithinKStops_hpp */
