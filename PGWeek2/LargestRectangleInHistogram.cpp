//
//  LargestRectangleInHistogram.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/4.
//

#include "LargestRectangleInHistogram.hpp"
#include <stack>


int LargestRectangleInHistogram::largestRectangleArea(std::vector<int>& heights) {
    std::stack<std::pair<int, int>> recToConsider; // id, height
    int sol = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        int prevId = i;
        while (!recToConsider.empty() && heights[i] < recToConsider.top().second) {
            
            sol = std::max(sol, recToConsider.top().second * (i- recToConsider.top().first));
            
            prevId = recToConsider.top().first;
            recToConsider.pop();
        }
        
        recToConsider.push(std::make_pair(prevId, heights[i]));
    }
    
    while (!recToConsider.empty()) {
        sol = std::max(sol, recToConsider.top().second * (int(heights.size()) - recToConsider.top().first));
        recToConsider.pop();
    }
    return sol;
}
