//
//  AddTwoNumbers.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/9.
//

#include "AddTwoNumbers.hpp"


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *sol = new ListNode();
    auto *curr = sol;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        if (l1 == nullptr && l2 == nullptr) {
            curr->next = new ListNode(carry);
            carry = 0;
        } else if (l1 == nullptr) {
            curr->next = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        } else if (l2 == nullptr) {
            curr->next = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        } else {
            curr->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    return sol->next;
}
