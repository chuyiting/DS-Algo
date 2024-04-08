//
//  MergeTwoSortedList.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/7.
//

#ifndef MergeTwoSortedList_hpp
#define MergeTwoSortedList_hpp

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeTwoSortedList {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2);
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2);
};

#endif /* MergeTwoSortedList_hpp */
