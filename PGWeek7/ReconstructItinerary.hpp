//
//  ReconstructItinerary.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/5/7.
//

#ifndef ReconstructItinerary_hpp
#define ReconstructItinerary_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

class ReconstructItnerary {
    std::vector<std::string> sol;
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets);
    
    bool dfs(std::unordered_map<std::string, std::multiset<std::string>> graph, std::string curr, int ticketsLeft);
};

#endif /* ReconstructItinerary_hpp */
