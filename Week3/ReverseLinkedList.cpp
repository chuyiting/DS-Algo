//
//  ReverseLinkedList.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/26.
//

#include "ReverseLinkedList.hpp"

ListNode*  ReverseLinkedList::reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    
    while (curr != nullptr) {
        ListNode *forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    
    return curr;
}

ListNode*  ReverseLinkedList::reverseListRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* next = head->next;
    ListNode* ans = reverseList(next);
    next->next = head;
    head->next = nullptr;
    
    return ans;
}
