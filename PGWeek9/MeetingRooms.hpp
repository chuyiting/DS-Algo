//
//  MeetingRooms.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#ifndef MeetingRooms_hpp
#define MeetingRooms_hpp

#include <stdio.h>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MeetingRoom {
public:
    bool canAttendMeetings(std::vector<Interval>& intervals);
};

#endif /* MeetingRooms_hpp */
