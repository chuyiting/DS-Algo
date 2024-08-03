//
//  NumberOf1Bits.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "NumberOf1Bits.hpp"

int NumberOf1Bits::hammingWeight(int n) {
    int sol = 0;
    while (n != 0) {
        if ((n & 0x1) != 0) sol++;
        n = n >> 1;
    }
    return sol;
}
