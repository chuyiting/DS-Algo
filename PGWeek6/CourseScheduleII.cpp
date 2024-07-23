//
//  CourseScheduleII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#include "CourseScheduleII.hpp"
#include <queue>

std::vector<int> CourseScheduleII::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> inDegrees(numCourses, 0);
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>());
    for (const auto&p : prerequisites) {
        adjList[p[1]].push_back(p[0]);
        inDegrees[p[0]]++;
    }
    
    std::queue<int> q;
    for (int i = 0; i < numCourses;i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    
    std::vector<int> sol;
    int numGoodCourses = 0;
    while (!q.empty()) {
        sol.push_back(q.front());
        for (const auto& nxt : adjList[q.front()]) {
            inDegrees[nxt]--;
            if (inDegrees[nxt] == 0) {
                q.push(nxt);
            }
        }
        q.pop();
        numGoodCourses++;
    }
    
    return numCourses == numGoodCourses ? sol : std::vector<int>();
    
}
