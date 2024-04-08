//
//  RemoveNthNodeFromEndOfList.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/8.
//

#include "RemoveNthNodeFromEndOfList.hpp"

ListNode* RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    auto *curr = head;
    while (curr != nullptr) {
        curr = curr->next;
        count++;
    }
    
    if (n == count) {
        return head->next;
    }
    
    curr = head;
    while (count > n+1) {
        curr = curr->next;
        count--;
    }
    
    curr->next = curr->next->next;
    return head;
}


ListNode* RemoveNthNodeFromEndOfList::removeNthFromEndOnePass(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (n > 0) {
        fast = fast->next;
        n--;
    }
    
    if (fast == nullptr) {
        return head->next;
    }
    
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

ListNode* RemoveNthNodeFromEndOfList::removeNthFromEndOnePassDummyNode(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode* fast = head;
    ListNode* slow = dummy;
    while (n > 0) {
        fast = fast->next;
        n--;
    }
    
    
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}
