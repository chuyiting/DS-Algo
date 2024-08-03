//
//  MaximumSubarray.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#ifndef MaximumSubarray_hpp
#define MaximumSubarray_hpp

#include <stdio.h>
#include <vector>

class MaximumSubarray {
public:
    int maxSubArray(std::vector<int>& nums);
    int maxSubArrayDivideAndConquer(std::vector<int>& nums);
    int maxSubArrayDivideAndConquerHelper(std::vector<int>& nums, int i, int j);
};

#endif /* MaximumSubarray_hpp */
