//
//  LinkedListCycle.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/26.
//

#include "LinkedListCycle.hpp"
#include <unordered_set>

bool LinkedListCycle::hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)  return false;
    auto tortoise = head;
    auto hare = head->next->next;
    while (hare != NULL && hare->next != NULL) {
        if (tortoise == hare) {
            return true;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return false;
}

bool LinkedListCycle::hasCycle2(ListNode *head) {
    std::unordered_set<ListNode*> visited;
    while (head != NULL) {
        if (visited.find(head) != visited.end()) {
            return true;
        } else {
            visited.insert(head);
            head = head->next;
        }
    }
    return false;
}


