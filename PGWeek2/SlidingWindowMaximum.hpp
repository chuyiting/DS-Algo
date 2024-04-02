//
//  SlidingWindowMaximum.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/1.
//

#ifndef SlidingWindowMaximum_hpp
#define SlidingWindowMaximum_hpp

#include <stdio.h>
#include <vector>

class SlidingWindowMaximum {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
    std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int k);
};

#endif /* SlidingWindowMaximum_hpp */
