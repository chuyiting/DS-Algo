//
//  PlusOne.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "PlusOne.hpp"

std::vector<int> PlusOne::plusOne(std::vector<int>& digits) {
    int i = digits.size();
    do {
        i--;
        digits[i] = (digits[i] + 1) % 10;
    } while (i >= 1 && digits[i] == 0);
    
    if(digits[0] == 0) {
        digits.push_back(0);
        digits[0] = 1;
    }
    return digits;
}
