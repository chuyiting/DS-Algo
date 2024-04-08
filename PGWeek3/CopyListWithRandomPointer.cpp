//
//  CopyListWithRandomPointer.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/8.
//

#include "CopyListWithRandomPointer.hpp"
#include <unordered_map>

Node* CopyListWithRandomPointer::copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    std::unordered_map<Node*, Node*> nodeMap;
    
    auto *curr = head;
    while (curr != nullptr) {
        Node *nodeCpy = new Node(curr->val);
        nodeMap[curr] = nodeCpy;
        curr = curr->next;
    }
    
    curr = head;
    while (curr != nullptr) {
        nodeMap[curr]->next = curr->next == nullptr ? nullptr : nodeMap[curr->next];
        nodeMap[curr]->random = curr->random == nullptr ? nullptr : nodeMap[curr->random];
        
        curr = curr->next;
    }
    
    return nodeMap[head];
}
