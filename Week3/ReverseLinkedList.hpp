//
//  ReverseLinkedList.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/26.
//

#ifndef ReverseLinkedList_hpp
#define ReverseLinkedList_hpp

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class ReverseLinkedList {
public:
    
    ListNode* reverseList(ListNode* head);
    ListNode* reverseListRecursive(ListNode* head);
};

#endif /* ReverseLinkedList_hpp */
