//
//  CountGoodNodesInBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#include "CountGoodNodesInBinaryTree.hpp"
#include <stack>

int CountGoodNodesInBinaryTree::goodNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    
    if (root->val >= this->currMax) {
        int oldCurrMax = this->currMax;
        this->currMax = root->val;
        int sol = 1 + goodNodes(root->left) + goodNodes(root->right);
        this->currMax = oldCurrMax;
        return sol;
    } else {
        return goodNodes(root->left) + goodNodes(root->right);
    }
    
}
