//
//  KthLargest.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/19.
//

#include "KthLargest.hpp"


KthLargest::KthLargest(int k, std::vector<int>& nums) {
    for (const auto &num : nums) {
        this->minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    this->k = k;
}

int KthLargest::add(int val) {
    this->minHeap.push(val);
    if (minHeap.size() > k) {
        this->minHeap.pop();
    }
    return this->minHeap.top();
}
