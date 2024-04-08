//
//  MergeTwoSortedList.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/7.
//

#include "MergeTwoSortedList.hpp"

ListNode* MergeTwoSortedList::mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *sol = nullptr;
    ListNode *curr = nullptr;
    
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1 -> val < list2 -> val) {
            if (sol == nullptr) {
                sol = new ListNode(list1->val);
                curr = sol;
            } else {
                curr->next = new ListNode(list1->val);
                curr = curr->next;
            }
            
            list1 = list1->next;
        } else {
            if (sol == nullptr) {
                sol = new ListNode(list2->val);
                curr = sol;
            } else {
                curr->next = new ListNode(list2->val);
                curr = curr->next;
            }
            
            list2 = list2->next;
        }
    }
    
    while (list1 != nullptr) {
            if (sol == nullptr) {
                return list1;
            } else {
                curr->next = list1;
                list1 = nullptr;
            }
        }
        
        while (list2 != nullptr) {
            if (sol == nullptr) {
                return list2;
            } else {
                curr->next = list2;
                list2 = nullptr;
            }
        }
        
    
    return sol;
}

ListNode* MergeTwoSortedList::mergeTwoLists2(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode();
    auto curr = dummy;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    
    if (list1 != nullptr) {
        curr->next = list1;
    }
    
    if (list2 != nullptr) {
        curr->next = list2;
    }
    return dummy->next;
    
}

ListNode* MergeTwoSortedList::mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    
    if (list2 == nullptr) {
        return list1;
    }
    
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
