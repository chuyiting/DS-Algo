//
//  GasStation.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#include "GasStation.hpp"

/*
 Difficult O(n) solution!!
 */
int GasStation::canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    
    int sum = 0;
    int currSum = 0;
    int sol = 0;
    for (int i = 0; i < gas.size(); i++) {
        int surplus = gas[i] - cost[i];
        sum += surplus;
        currSum += surplus;
        if (currSum < 0) {
            sol = i+1;
            currSum = 0;
        }
    }
    return sum >= 0 ? sol : -1;
}
