//
//  CloneGraph.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/29.
//

#ifndef CloneGraph_hpp
#define CloneGraph_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class CloneGraph {
    std::unordered_map<Node*, Node*> oldToNewMap;
    std::unordered_set<Node*> visited;
public:
    Node* cloneGraph(Node* node);
};

#endif /* CloneGraph_hpp */
