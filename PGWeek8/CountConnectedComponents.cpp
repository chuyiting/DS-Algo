//
//  CountConnectedComponents.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/11.
//

#include "CountConnectedComponents.hpp"
#include <stack>
#include <unordered_set>

int CountConnectedComponents::countComponents(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    std::unordered_set<int> visited;
    
    int numOfComponents = 0;
    for (int i = 0; i < n; i++) {
        if (visited.count(i) != 0) continue;
        std::stack<int> stack;
        stack.push(i);
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            visited.insert(curr);
            for (const auto &nei : graph[curr]) {
                if (visited.count(nei) == 0) {
                    stack.push(nei);
                }
            }
        }
        numOfComponents++;
    }
    return numOfComponents;
}
