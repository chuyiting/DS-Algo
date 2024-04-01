//
//  BestTimeToBuyAndSellStock.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/31.
//

#include "BestTimeToBuyAndSellStock.hpp"

int BestTimeToBuyAndSellStock::maxProfit(std::vector<int>& prices) {
    int currSmallest = INT_MAX;
    int sol = 0;
    for (int i = 1; i < prices.size(); i++) {
        currSmallest = std::min(currSmallest, prices[i-1]);
        sol = std::max(sol, prices[i] - currSmallest);
    }
    
    return sol;
}
