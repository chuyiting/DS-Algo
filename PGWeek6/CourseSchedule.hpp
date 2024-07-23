//
//  CourseSchedule.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#ifndef CourseSchedule_hpp
#define CourseSchedule_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class CourseSchedule {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
    
    bool canFinishTopo(int numCourses, std::vector<std::vector<int>>& prerequisites);
    
    void createAdjList(std::vector<std::vector<int>>& prerequisites, std::unordered_map<int, std::vector<int>>& adjList);
    
    void createAdjListWithInDegrees(std::vector<std::vector<int>>& prerequisites, std::unordered_map<int, std::vector<int>>& adjList, std::unordered_map<int, int> &inDegrees);
    
    bool isThereDirectedCycle(std::unordered_set<int> &visited, std::unordered_map<int, std::vector<int>>& adjList, int start);
};

#endif /* CourseSchedule_hpp */
