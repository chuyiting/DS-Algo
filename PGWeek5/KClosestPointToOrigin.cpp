//
//  KClosestPointToOrigin.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/23.
//

#include "KClosestPointToOrigin.hpp"
#include <algorithm>

struct PtCmp {
    bool operator()(const std::vector<int>& p1, const std::vector<int>& p2) {
        return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
    }
};

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::make_heap(points.begin(), points.end(), PtCmp());
    while (points.size() > k) {
        pop_heap(points.begin(), points.end(), PtCmp());
        points.pop_back();
    }
    
    return points;
}
