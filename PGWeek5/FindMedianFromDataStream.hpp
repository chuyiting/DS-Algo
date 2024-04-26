//
//  FindMedianFromDataStream.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/26.
//

#ifndef FindMedianFromDataStream_hpp
#define FindMedianFromDataStream_hpp

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>


class MedianFinder {
    std::priority_queue<int> smallValueMaxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> largeValueMinHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallValueMaxHeap.push(num);
        if (!smallValueMaxHeap.empty() && !largeValueMinHeap.empty()
            && smallValueMaxHeap.top() > largeValueMinHeap.top()) {
            int element = smallValueMaxHeap.top();
            largeValueMinHeap.push(element);
            smallValueMaxHeap.pop();
        }
        
        if (smallValueMaxHeap.size() > largeValueMinHeap.size()+1) {
            int element = smallValueMaxHeap.top();
            largeValueMinHeap.push(element);
            smallValueMaxHeap.pop();
        }
        
        if (smallValueMaxHeap.size() + 1 < largeValueMinHeap.size()) {
            int element = largeValueMinHeap.top();
            smallValueMaxHeap.push(element);
            largeValueMinHeap.pop();
        }
        
    }
    
    double findMedian() {
        if (smallValueMaxHeap.size() > largeValueMinHeap.size()) {
            return smallValueMaxHeap.top();
        } else if (smallValueMaxHeap.size() < largeValueMinHeap.size()){
            return largeValueMinHeap.top();
        } else {
            return (largeValueMinHeap.top() + smallValueMaxHeap.top()) / 2.0;
        }
    }
};


#endif /* FindMedianFromDataStream_hpp */
