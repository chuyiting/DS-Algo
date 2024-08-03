//
//  MeetingRooms.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "MeetingRooms.hpp"

#include <algorithm>

bool doesConflict (Interval &i1, Interval &i2) {
    bool  notConflict = i1.start >= i2.end || i1.end <=  i2.start;
    return !notConflict;
}

bool MeetingRoom::canAttendMeetings(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](Interval &i1, Interval &i2){
        return i1.start < i2.start;
    });
    
    for (int i = 1; i < intervals.size(); i++) {
        if (doesConflict(intervals[i], intervals[i-1])) {
            return false;
        }
    }
    return true;
}
