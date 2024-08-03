//
//  ReverseInteger.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "ReverseInteger.hpp"
#include <climits>
#include <cmath>
#include <vector>

/*
 practice to code this in a cleaner way
 */
int ReverseInteger::reverse(int x) {
    if (x == 0) return 0;
    int x_cp = abs(x);
    int numOfDigit = 0;
    while (x_cp > 0) {
        x_cp /= 10;
        numOfDigit++;
    }
    int sol = 0;
    std::vector<int> tens(numOfDigit - 1, 1);
    for (int i = 1; i < tens.size(); i++) {
        tens[i] = tens[i - 1] * 10;
    }

    for (int i = 0; i < numOfDigit - 1; i++) {
        int digit = x % 10;
        sol += tens[numOfDigit - 2 - i] * digit;
        x /= 10;
    }
    
    if (abs(sol) < (INT_MAX / 10)) {
        return sol * 10 + x;
    } else if (abs(sol) == (INT_MAX / 10)) {
        if ((x > 0 && x <= 7) || (x < 0 && x >= -8)) {
            return sol * 10 + x;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
