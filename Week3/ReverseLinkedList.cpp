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

ListNode*  ReverseLinkedList::reverseListreRecursive(ListNode* head) {
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
