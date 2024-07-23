//
//  CourseSchedule.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#include "CourseSchedule.hpp"
#include <queue>

bool CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::vector<int>> adjList;
    std::unordered_set<int> visited;
    createAdjList(prerequisites, adjList);
    
    for (int course = 0; course < numCourses; course++) {
        if (isThereDirectedCycle(visited, adjList, course)) return false;
        visited.clear();
    }
    
    return true;
}


bool CourseSchedule::canFinishTopo(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::vector<int>> adjList;
    std::unordered_map<int, int> inDegrees;
    createAdjListWithInDegrees(prerequisites, adjList, inDegrees);
    
    std::queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees.count(i) == 0) {
            q.push(i);
        }
    }
    
    int goodCourses = 0;
    while (!q.empty()) {
        for (const auto&next : adjList[q.front()]) {
            inDegrees[next]--;
            if (inDegrees[next] == 0) {
                q.push(next);
            }
        }
        
        q.pop();
        goodCourses++;
    }
    
    return goodCourses == numCourses;
}


void CourseSchedule::createAdjList(std::vector<std::vector<int>>& prerequisites, std::unordered_map<int, std::vector<int>>& adjList) {
    for (const auto &p : prerequisites) {
        if (adjList.count(p[1]) == 0) {
            adjList[p[1]] = {};
        }
        
        adjList[p[1]].push_back(p[0]);
    }
}

void CourseSchedule::createAdjListWithInDegrees(std::vector<std::vector<int>>& prerequisites, std::unordered_map<int, std::vector<int>>& adjList, std::unordered_map<int, int> &inDegrees) {
    for (const auto &p : prerequisites) {
        if (adjList.count(p[1]) == 0) {
            adjList[p[1]] = {};
        }
        
        if (inDegrees.count(p[0]) == 0) {
            inDegrees[p[0]] = 0;
        }
        inDegrees[p[0]]++;
        adjList[p[1]].push_back(p[0]);
    }
}

bool CourseSchedule::isThereDirectedCycle(std::unordered_set<int> &visited, std::unordered_map<int, std::vector<int>>& adjList, int start) {
    if (visited.count(start) != 0) return true;
    visited.insert(start);
    for (const auto &nxt : adjList[start] ) {
        if (isThereDirectedCycle(visited, adjList, nxt)) {
            return true;
        }
    }
    visited.erase(start);
    adjList[start].clear();
    return false;
}
