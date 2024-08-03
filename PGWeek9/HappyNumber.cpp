//
//  HappyNumber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "HappyNumber.hpp"
#include <unordered_set>

bool HappyNumber::isHappy(int n) {
    std::unordered_set<int> visited;
    
    while (n != 1) {
        int nxt = 0;
        while (n != 0) {
            nxt += (n%10) * (n%10);
            n = n/10;
        }
        n = nxt;
        
        if (visited.count(n) != 0) break;
        visited.insert(nxt);
    }
    return n == 1;
}
