//
//  ProductOfArrayExceptSelf.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/10.
//

#include "ProductOfArrayExceptSelf.hpp"

std::vector<int> ProductOfArrayExceptSelf::productExceptSelf(std::vector<int>& nums){
    std::vector<int> frontAccum(nums.size());
    std::vector<int> backAccum(nums.size());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            frontAccum[i] = nums[0];
            backAccum[nums.size()-1-i] = nums[nums.size()-1];
        } else {
            frontAccum[i] = frontAccum[i-1] * nums[i];
            backAccum[nums.size()-1-i] = nums[nums.size()-1-i] * backAccum[nums.size()-i];
        }
        
    }
    
    std::vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int front = i == 0 ? 1 : frontAccum[i-1];
        int back = i == nums.size()-1 ? 1 : backAccum[i+1];
        ans.push_back(front * back);
    }
    
    return ans;
}
