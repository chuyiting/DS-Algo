//
//  CarFleet.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/4.
//

#include "CarFleet.hpp"
#include <algorithm>
#include <stack>

int CarFleet::carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, int>> positionSpeed;
    for (int i = 0; i < position.size(); i++) {
        positionSpeed.push_back(std::make_pair(position[i], speed[i]));
    }
    
    // sort it by position in descending order
    std::sort(positionSpeed.begin(), positionSpeed.end(), [](const auto& p1, const auto&p2){return p1.first > p2.first;});
    
    std::stack<double> carFleet; // store the timestamp that each car fleet arrives at the destination
    
    for (const auto&car: positionSpeed) {
        double arriveTime = (target - car.first) / car.second;
        if (carFleet.empty() || arriveTime > carFleet.top()) {
            carFleet.push(arriveTime);
        }
    }
    
    return carFleet.size();
}
