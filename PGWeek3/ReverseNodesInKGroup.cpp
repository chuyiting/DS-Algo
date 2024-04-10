//
//  ReverseNodesInKGroup.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#include "ReverseNodesInKGroup.hpp"

ListNode*  ReverseNodesInKGroup::reverseKGroup(ListNode* head, int k) {
    int count = 0;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *curr = head;
    ListNode *gpStart = dummy;
    
    while (curr != nullptr) {
        count++;
        if (count % k != 0) {
            curr = curr->next;
            continue;
        }
        
        auto *next = curr->next;
        curr->next = nullptr;
        auto se = this->reverseList(gpStart->next);
        gpStart->next = se.first;
        se.second->next = next;
        gpStart = se.second;
        curr = next;
    }
    
    return dummy->next;
}

std::pair<ListNode*, ListNode*> ReverseNodesInKGroup::reverseList (ListNode *ls) {
    ListNode *prev = nullptr;
    ListNode *curr = ls;
    
    ListNode *newEnd = curr;
    while (curr != nullptr) {
        auto *next = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    
    return {prev, newEnd};
}
