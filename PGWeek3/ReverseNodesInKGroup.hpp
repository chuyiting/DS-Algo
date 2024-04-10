//
//  ReverseNodesInKGroup.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#ifndef ReverseNodesInKGroup_hpp
#define ReverseNodesInKGroup_hpp

#include <stdio.h>
#include <utility>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class ReverseNodesInKGroup {
public:
    ListNode* reverseKGroup(ListNode* head, int k);
    std::pair<ListNode*, ListNode*> reverseList (ListNode *ls);
};

#endif /* ReverseNodesInKGroup_hpp */
