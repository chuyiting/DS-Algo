//
//  TwoSumII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/30.
//

#include "TwoSumII.hpp"

std::vector<int> TwoSumII::twoSum(std::vector<int>& numbers, int target) {
    int l = 0, r = numbers.size()-1;
            while (r > l) {
                if (numbers[l] + numbers[r] == target) {
                    return {l+1, r+1};
                } else if (numbers[l] + numbers[r] < target) {
                    l++;
                } else {
                    r--;
                }
                
            }
            return {};
}
