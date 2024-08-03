//
//  SumOfTwoIntegers.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "SumOfTwoIntegers.hpp"

int SumOfTwoIntegers::getSum(int a, int b) {
    int carry = a&b;
    int sol = a ^ b;
    while (carry) {
        int prevSol = sol;
        sol = sol ^ (carry << 1);
        carry = prevSol & (carry << 1);
    }
    return sol;
}
