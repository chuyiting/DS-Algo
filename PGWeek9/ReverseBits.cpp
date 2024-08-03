//
//  ReverseBits.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "ReverseBits.hpp"

uint32_t ReverseBits::reverseBits(uint32_t n) {
    uint32_t sol = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & 1) != 0) {
            sol = sol | 1;
        }
        n = n >> 1;
        if (i != 31) {
            sol = sol << 1;
        }
    }
    return sol;
}
