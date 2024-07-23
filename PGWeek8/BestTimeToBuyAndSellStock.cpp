//
//  BestTimeToBuyAndSellStock.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/17.
//

#include "BestTimeToBuyAndSellStock.hpp"
#include <algorithm>
#include <climits>

int BestTimeToBuyAndSellStockWithCooldown::maxProfit(std::vector<int>& prices) {
    std::vector<int> hasStock(prices.size(), 0);
    std::vector<int> noStock(prices.size(), 0);
    std::vector<int> coolDown(prices.size(), 0);
    
    coolDown[0] = INT_MIN;
    hasStock[0] = - prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        hasStock[i] = std::max(hasStock[i-1], noStock[i-1] - prices[i]);
        noStock[i] = std::max(noStock[i-1], coolDown[i-1]);
        coolDown[i] = hasStock[i-1] + prices[i];
    }
    
    
    return std::max({coolDown[prices.size()], noStock[prices.size()], hasStock[prices.size()]});
}
