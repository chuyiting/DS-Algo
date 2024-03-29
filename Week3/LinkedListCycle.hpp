//
//  LinkedListCycle.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/26.
//

#ifndef LinkedListCycle_hpp
#define LinkedListCycle_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle {
public:
    bool hasCycle(ListNode *head);
    bool hasCycle2(ListNode *head);
};

#endif /* LinkedListCycle_hpp */
