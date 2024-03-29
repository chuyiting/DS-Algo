//
//  FindTheDuplicateNumber.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/5.
//

#include "FindTheDuplicateNumber.hpp"
#include <vector>

int FindTheDuplicateNumber::findDuplicate(std::vector<int>& nums) {
    int tortoise = 0;
    int hare = 0;
    
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    
    hare = 0;
    
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    
    return hare; 
        
}
