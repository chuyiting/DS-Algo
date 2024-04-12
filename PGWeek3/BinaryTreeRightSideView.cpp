//
//  BinaryTreeRightSideView.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#include "BinaryTreeRightSideView.hpp"
#include <queue>


std::vector<int> BinaryTreeRightSideView::rightSideView(TreeNode* root) {
    if (root == nullptr)
        return {};
    std::vector<int> sol;
    std::queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        TreeNode* curr = nullptr;
        for (int i = 0; i < levelSize; i++) {
            curr = nodes.front();
            if (curr->left != nullptr)
                nodes.push(curr->left);
            if (curr->right != nullptr)
                nodes.push(curr->right);
            nodes.pop();
        }

        sol.push_back(curr->val);
    }
    return sol;
    
}
