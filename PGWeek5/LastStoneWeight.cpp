//
//  LastStoneWeight.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/23.
//

#include "LastStoneWeight.hpp"
#include <queue>

int lastStoneWeight(std::vector<int> &stones) {
    std::priority_queue<int> maxHeap;
    for(const auto& stone: stones) {
        maxHeap.push(stone);
    }
    
    while (maxHeap.size() > 1) {
        int element1 = maxHeap.top();
        maxHeap.pop();
        int element2 = maxHeap.top();
        maxHeap.pop();
        if (element1 == element2) {
            continue;
        } else {
            maxHeap.push(element1-element2);
        }
    }
    
    return maxHeap.size() == 0? 0 : maxHeap.top();
}
