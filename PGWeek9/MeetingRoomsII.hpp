//
//  MeetingRoomsII.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#ifndef MeetingRoomsII_hpp
#define MeetingRoomsII_hpp

#include <stdio.h>
#include <vector>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MeetingRoomsII {
public:
    int minMeetingRooms(std::vector<Interval>& intervals);
};

#endif /* MeetingRoomsII_hpp */
