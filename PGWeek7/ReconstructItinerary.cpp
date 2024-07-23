//
//  ReconstructItinerary.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/5/7.
//

#include "ReconstructItinerary.hpp"
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <iterator>

std::vector<std::string> ReconstructItnerary::findItinerary(std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string, std::multiset<std::string>> graph;
    for (const auto& ticket : tickets) {
        if (graph.count(ticket[0]) == 0) {
            graph[ticket[0]] = {};
        }
        graph[ticket[0]].insert(ticket[1]);
    }
    

    this->dfs(graph, "JFK", tickets.size());
    return this->sol;
}


bool ReconstructItnerary::dfs(std::unordered_map<std::string, std::multiset<std::string>> graph, std::string curr, int ticketsLeft) {
    int numOfNei = graph[curr].size();
    if (numOfNei == 1 && ticketsLeft == 1) {
        this->sol.push_back(*graph[curr].begin());
        return true;
    }
    
    if (ticketsLeft > 0 && numOfNei == 0) {
        return false;
    }
    
    
    for (int i = 0; i < numOfNei; i++) {
        auto &nxts = graph[curr];
        auto nxt = std::next(nxts.begin(), i);
        this->sol.push_back(*nxt);
        std::string n = *nxt;
        nxts.erase(nxt);
        if (dfs(graph, n, ticketsLeft-1)) return true;
        this->sol.pop_back();
        nxts.insert(n);
    }
    return false;
}
