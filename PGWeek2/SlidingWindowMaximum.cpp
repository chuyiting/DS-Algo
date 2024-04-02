//
//  SlidingWindowMaximum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/1.
//

#include "SlidingWindowMaximum.hpp"
#include <deque>
#include <utility>

std::vector<int> SlidingWindowMaximum::maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<std::pair<int, int>> maxQueue;
    std::vector<int> sol(nums.size()-k+1, 0);
    
    maxQueue.push_back({nums[0], 0});
    for (int i = 1; i < k; i++) {
        if (nums[i] > maxQueue.front().first) {
            maxQueue.clear();
            maxQueue.push_front({nums[i], i});
        } else {
            while (maxQueue.back().first < nums[i]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back({nums[i], i});
        }
    }
    sol[0] = maxQueue.front().first;
    
    for (int i = k; i < nums.size(); i++) {
        while (maxQueue.front().second <= i-k) {
            maxQueue.pop_front();
        }
        
        if (nums[i] > maxQueue.front().first) {
            maxQueue.clear();
            maxQueue.push_front({nums[i], i});
        } else  {
            while (maxQueue.back().first < nums[i]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back({nums[i], i});
        }
        sol[i-k+1] = maxQueue.front().first;
    }
    return sol;
}

std::vector<int> SlidingWindowMaximum::maxSlidingWindow2(std::vector<int>& nums, int k) {
    std::deque<int> maxQueue;
    std::vector<int> sol;
    
    if (nums.size() == 1) {
        return nums;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        while (!maxQueue.empty() && nums[maxQueue.back()] < nums[i]) {
            maxQueue.pop_back();
        }
        maxQueue.push_back(i);
        
        if (maxQueue.front() <= i - k) {
            maxQueue.pop_front();
        }
        
        if (i >= k-1) {
            sol.push_back(nums[maxQueue.front()]);
        }
    }
    return sol;
}
