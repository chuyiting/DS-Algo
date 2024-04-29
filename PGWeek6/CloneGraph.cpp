//
//  CloneGraph.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#include "CloneGraph.hpp"

Node* CloneGraph::cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    if (visited.count(node) != 0) return oldToNewMap[node];
    
    Node *cpy = new Node(node->val);
    visited.insert(cpy);
    oldToNewMap[node] = cpy;
    for (auto *neighbor : node->neighbors) {
        cpy->neighbors.push_back(cloneGraph(neighbor));
    }
    return cpy;
}
