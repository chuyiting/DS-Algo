//
//  CountInversions.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/23.
//

#include "CountInversions.hpp"
#include <algorithm>

int CountInversions::countInversion(std::vector<int> &arr) {
    return countInversionHelper(arr);
}

int CountInversions::countInversionHelper(std::vector<int> arr){
    return countInvFromTo(arr, 0, arr.size()-1);
}

int CountInversions::countInvFromTo(std::vector<int> &arr, int begin, int end) {
    if (end - begin <= 0) return 0;
    
    int mid = (begin + end) / 2;
    int l = countInvFromTo(arr, begin, mid);
    int r = countInvFromTo(arr, mid+1, end);
    return countAndMerge(arr, begin, mid, mid+1, end) + l + r;
    
}

int CountInversions::countAndMerge(std::vector<int> &arr, int l1, int r1, int l2, int r2) {
    std::vector<int> merged;
    int count = 0;
    int begin = l1;
    while (l1 <= r1 && l2 <= r2) {
        if (arr[l1] < arr[l2]) {
            merged.push_back(arr[l1++]);
        } else {
            merged.push_back(arr[l2++]);
            count += (r1 - l1 +1);
        }
    }
    
    while (l1 <= r1) {
        merged.push_back(arr[l1++]);
    }
    
    while (l2 <= r2) {
        merged.push_back(arr[l2++]);
    }
    std::copy(merged.begin(), merged.end(), arr.begin()+begin);
    return count;
}

