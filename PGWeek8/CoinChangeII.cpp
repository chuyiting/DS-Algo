//
//  CoinChangeII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/18.
//

#include "CoinChangeII.hpp"
#include <unordered_set>

int CoinChange::change(int amount, std::vector<int>& coins) {
    std::vector<std::vector<int>> comb(coins.size()+1, std::vector<int>(amount+1, 0));
    for (int i = 0; i < comb.size(); i++) {
        comb[i][0] = 1;
    }
    
    for (int i = 1; i < comb.size(); i++) {
        for (int j = 1; j < amount+1; j++) {
            comb[i][j] = comb[i-1][j] + comb[i][j-coins[i-1]];
        }
    }
    
    return comb[coins.size()][amount];
}
