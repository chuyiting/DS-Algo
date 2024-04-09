//
//  MergeKList.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/9.
//

#ifndef MergeKList_hpp
#define MergeKList_hpp

#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class MergeKSortedList {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
    ListNode* mergeKLists2(std::vector<ListNode*>& lists);
};

#endif /* MergeKList_hpp */
