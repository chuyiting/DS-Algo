//
//  ReorderList.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/7.
//

#include "ReorderList.hpp"
#include <cmath>


void ReorderList::reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return;
    }
    
    auto *curr = head;
    while (curr -> next -> next != nullptr) {
        curr = curr->next;
    }
    
    auto *next = head->next;
    head->next = curr->next;
    curr->next = nullptr;
    reorderList(next);
    head->next->next = next;
}

void ReorderList::reorderList2(ListNode* head) {

    auto* slow = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    auto *second = slow->next;
    slow->next = nullptr;
    auto *first = head;
    
    ListNode *prev = nullptr;
    while (second != nullptr) {
        auto *temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }
    
    second = prev;
    while (second != nullptr) {
        auto *temp = first->next;
        first->next = second;
        second = second->next;
        first->next->next = temp;
        first = temp;
    }
}
