//
//  CountInversions.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/23.
//

#ifndef CountInversions_hpp
#define CountInversions_hpp

#include <vector>
#include <stdio.h>


class CountInversions {
public:
    int countInversion(std::vector<int> &arr);
    
    // solution 1 merge sort
    int countInversionHelper(std::vector<int> arr);
    int countInvFromTo(std::vector<int> &arr, int begin, int end);
    int countAndMerge(std::vector<int> &arr, int l1, int r1, int l2, int r2);
    
    // solution 2 AVL tree
};

#endif /* CountInversions_hpp */
