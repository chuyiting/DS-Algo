//
//  KthLargestElementInAnArray.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/23.
//

#ifndef KthLargestElementInAnArray_hpp
#define KthLargestElementInAnArray_hpp

#include <stdio.h>
#include <vector>

class KthLargestElementInAnArray {
public:
    int findKthLargest(std::vector<int>& nums, int k);
    int findKthLargestQuickSelect(std::vector<int>& nums, int k);
    int quickSelect(std::vector<int>& nums, int k);
    int partition(std::vector<int>& nums, int begin, int end);
};

#endif /* KthLargestElementInAnArray_hpp */
