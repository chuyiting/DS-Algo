//
//  InsertInterval.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#ifndef InsertInterval_hpp
#define InsertInterval_hpp

#include <stdio.h>
#include <vector>

class InsertInterval {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);
};

#endif /* InsertInterval_hpp */
