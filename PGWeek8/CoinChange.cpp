//
//  CoinChange.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "CoinChange.hpp"
#include <climits>
#include <algorithm>

int CoinChanges::coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> minCoins(amount+1, -1);
    minCoins[0] = 0;
    for (int i = 1; i <= amount; i++) {
        int numOfCoins = INT_MAX;
        for (const auto &coin : coins) {
            if (i - coin >= 0 && minCoins[i-coin] != -1) {
                numOfCoins = std::min(numOfCoins, minCoins[i-coin]+1);
            }
        }
        if (numOfCoins != INT_MAX) {
            minCoins[i]= numOfCoins;
        }
    }
    return minCoins[amount];
}
