//
//  CheapestFlightsWithinKStops.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/6.
//

#include "CheapestFlightsWithinKStops.hpp"
#include <unordered_map>
#include <utility>
#include <queue>
#include <climits>

int CheapestFlightsWithinKStops::findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
    std::vector<std::vector<std::pair<int, int>>> graph(n+1);
    for (const auto &flight : flights) {
        graph[flight[0]].push_back({flight[1], flight[2]});
    }
    
    std::vector<int> prices(n, INT_MAX);
    prices[src] = 0;
    std::queue<std::vector<int>> q;
    q.push({src, 0, 0});
    int i = 0;
    
    while (!q.empty()) {
        int v = q.front()[0];
        int price = q.front()[1];
        int noStops = q.front()[2];
        q.pop();
        for (const auto& nei : graph[v]) {
            int newPrice = price + nei.second;
            if (newPrice < prices[nei.first] && noStops <= k) {
                prices[nei.first] = newPrice;
                q.push({nei.first, newPrice, noStops+1});
            }
        }
        
    }
    
    if (prices[dst] == INT_MAX) return -1;
    return prices[dst];
}
