//
//  DailyTemperature.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/4.
//

#include "DailyTemperature.hpp"
#include <stack>

std::vector<int> DailyTemperature::dailyTemperature(std::vector<int>& temperatures)  {
    std::vector<int> sol(temperatures.size(), 0);
    std::stack<int> tempStack;
    for (int i = 0; i < sol.size(); i++) {
        while (!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()]) {
            sol[tempStack.top()] = i - tempStack.top();
            tempStack.pop();
        }
        tempStack.push(i);
    }
    
    return sol;
}
