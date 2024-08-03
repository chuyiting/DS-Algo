//
//  MeetingRoomsII.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "MeetingRoomsII.hpp"
#include <utility>
#include <algorithm>

/*
 Difficult problem!!
 Max overlap of all time
 */
int MeetingRoomsII::minMeetingRooms(std::vector<Interval>& intervals) {
    std::vector<std::pair<int, bool>> endpoints; //  (pos, isBegin)
    for (auto &interval: intervals){
        endpoints.push_back({interval.start, true});
        endpoints.push_back({interval.end, false});
    }
    
    std::sort(endpoints.begin(), endpoints.end(), [](std::pair<int, bool> &e1, std::pair<int, bool> &e2){
        if (e1.first == e2.first) {
            return !e1.second;
        } else {
            return e1.first < e2.first;
        }
    });
    
    int sol = 0;
    int currOverlap = 0;
    for (const auto &e : endpoints) {
        if (e.second) {
            currOverlap++;
            sol = std::max(sol, currOverlap);
        } else {
            currOverlap--;
        }
    }
    return sol;
}

