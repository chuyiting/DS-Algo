//
//  RemoveNthNodeFromEndOfList.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/8.
//

#ifndef RemoveNthNodeFromEndOfList_hpp
#define RemoveNthNodeFromEndOfList_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode* next) : val(val), next(next){};
};

class RemoveNthNodeFromEndOfList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEndOnePass(ListNode* head, int n);
    ListNode* removeNthFromEndOnePassDummyNode(ListNode* head, int n);
};

#endif /* RemoveNthNodeFromEndOfList_hpp */
