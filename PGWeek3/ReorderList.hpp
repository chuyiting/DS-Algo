//
//  ReorderList.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/7.
//

#ifndef ReorderList_hpp
#define ReorderList_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReorderList {
public:
    void reorderList(ListNode* head);
    void reorderList2(ListNode* head);
};

#endif /* ReorderList_hpp */
