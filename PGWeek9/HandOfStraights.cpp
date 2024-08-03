//
//  HandOfStraights.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/30.
//

#include "HandOfStraights.hpp"
#include <unordered_map>
#include <queue>

bool HandOfStraights::isNStraightHand(std::vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
       
    std::unordered_map<int, int> count;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (auto &card: hand) {
        count[card]++;
        minHeap.push(card);
    }
    
//    for (auto &card : hand) {
//        if (count[card] == 0) continue;
//        int begin = card;
//        while (count.count(begin) > 0 && count[begin] > 0) {
//            begin--;
//        }
//
//        for (int i = begin+1; i <= begin+groupSize; i++) {
//            if (count.count(i) == 0 || count[i] == 0) {
//                return false;
//            } else {
//                count[i]--;
//            }
//        }
//    }
    
    while (!minHeap.empty()) {
        int begin = minHeap.top();
        while (count[begin] == 0) {
            minHeap.pop();
            begin = minHeap.top();
        }
        
        for (int i = begin; i < begin+groupSize; i++) {
            if (count.count(i) == 0 || count[i] == 0) {
                return false;
            } else {
                count[i]--;
            }
        }
    }
    return true;
}
