//
//  BinaryTreeLevelOrderTraversal.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#include "BinaryTreeLevelOrderTraversal.hpp"
#include <queue>
#include <utility>

std::vector<std::vector<int>> BinaryTreeLevelOrderTraversal::levelOrder(TreeNode* root) {
        
    if (root == nullptr) return {};
    std::vector<std::vector<int>> sol;
    std::queue<TreeNode*> nodes;
    nodes.push(root);
        
    while (!nodes.empty()) {
        int qSize = nodes.size();
        std::vector<int> currLevel;
        for (int i = 0; i < qSize; i++) {
            auto *curr = nodes.front();
            currLevel.push_back(curr->val);
            if (curr->left != nullptr) nodes.push(curr->left);
            if (curr->right != nullptr) nodes.push(curr->right);
            nodes.pop();
        }
        
        sol.push_back(currLevel);
    }

    return sol;
}


