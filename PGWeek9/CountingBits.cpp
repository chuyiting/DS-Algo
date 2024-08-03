//
//  CountingBits.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/3.
//

#include "CountingBits.hpp"

std::vector<int> CountingBits::countBits(int n) {
    std::vector<int> sol(n+1);
    std::vector<int> numOfTrailingZeros(n+1);
    sol[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (numOfTrailingZeros[i-1] == 0) {
            sol[i] = sol[i-1]+1;
            numOfTrailingZeros[i] = numOfTrailingZeros[i/2]+1;
        } else {
            sol[i] = sol[i-1] - numOfTrailingZeros[i-1] + 1;
            numOfTrailingZeros[i] = 0;
        }
    }
    return sol;
    
}
