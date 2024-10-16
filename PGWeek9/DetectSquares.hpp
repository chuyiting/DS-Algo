//
//  DetectSquares.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#ifndef DetectSquares_hpp
#define DetectSquares_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cmath>

struct PointHash {
public:
    size_t operator()(const std::vector<int> &p) const {
        return p[0]*1000 + p[1];
    }
};

class DetectSquares {
public:
    std::unordered_map<std::vector<int>, int, PointHash> pts;
    std::unordered_map<int, std::vector<int>> xList;
    DetectSquares() {
            
    }
        
    void add(std::vector<int> point) {
        pts[point]++;
        if (xList.count(point[0]) == 0) {
            xList[point[0]] = {point[1]};
        } else {
            xList[point[0]].push_back(point[1]);
        }
    }
        
    int count(std::vector<int> point) {
        int sol = 0;
        auto &ys = xList[point[0]];
        for (int i = 0; i < ys.size(); i++) {
            std::vector<int> pt = {point[0], ys[i]};
            int l = abs(pt[1] - point[1]);
            if (pts.count({pt[0]+l, pt[1]}) != 0 && pts.count({point[0]+l, point[1]}) != 0) {
                sol += pts[{pt[0]+l, pt[1]}] * pts[{point[0]+l, point[1]}] * pts[{pt[0], pt[1]}];
            }
            
            if (pts.count({pt[0]-l, pt[1]}) != 0 && pts.count({point[0]-l, point[1]}) != 0) {
                sol += pts[{pt[0]-l, pt[1]}] * pts[{point[0]+l, point[1]}] * pts[{pt[0], pt[1]}];
            }
        }
        return sol;
    }
};

#endif /* DetectSquares_hpp */
