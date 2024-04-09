//
//  MergeKList.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/9.
//

#include "MergeKList.hpp"
#include <algorithm>
#include <queue>
#include <vector>

ListNode* MergeKSortedList::mergeKLists(std::vector<ListNode*>& lists) {
    ListNode *dummy = new ListNode();
    auto *curr = dummy;
    while (std::any_of(lists.begin(), lists.end(), [](const auto *l){return l!=nullptr;})) {
        int currMin = INT_MAX;
        int currMinListId = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr && lists[i]->val < currMin) {
                currMin = lists[i]->val;
                currMinListId = i;
            }
        }
        curr->next = lists[currMinListId];
        lists[currMinListId] = lists[currMinListId]->next;
        curr = curr->next;
        
    }
    return dummy->next;
}

struct ListGreater {
    bool operator() (const ListNode *l1, const ListNode *l2) {
        return l2->val < l1->val;
    }
};

ListNode* MergeKSortedList::mergeKLists2(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, ListGreater> listNodeMinHeap;
    
    for (auto* list : lists) {
        listNodeMinHeap.push(list);
    }
    
    ListNode *dummy = new ListNode();
    auto *curr = dummy;
    while (!listNodeMinHeap.empty()) {
        curr -> next = listNodeMinHeap.top();
        auto *next = listNodeMinHeap.top()->next;
        listNodeMinHeap.pop();
        if (next != nullptr) {
            listNodeMinHeap.push(next);
        }
        curr = curr->next;
    }
    
    return dummy->next;
    
}
