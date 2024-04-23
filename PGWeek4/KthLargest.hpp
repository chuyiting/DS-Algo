//
//  KthLargest.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/19.
//

#ifndef KthLargest_hpp
#define KthLargest_hpp

#include <stdio.h>
#include <vector>
#include <queue>


class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>>  minHeap;
    int k;
public:
    KthLargest(int k, std::vector<int>& nums);
    int add(int val);
};

#endif /* KthLargest_hpp */
