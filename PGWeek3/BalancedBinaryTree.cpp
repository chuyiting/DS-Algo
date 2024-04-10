//
//  BalancedBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#include "BalancedBinaryTree.hpp"
#include <limits.h>
#include <cmath>
#include <algorithm>

bool BalancedBinaryTree::isBalanced(TreeNode* root) {
    int h = this->getHeight(root);
    if (h == INT_MIN) return false;
    return true;
}

int BalancedBinaryTree::getHeight(TreeNode *root) {
    if (root == nullptr) return -1;
    
    int lh = getHeight(root->left);
    if (lh == INT_MIN) {
        return INT_MIN;
    }
    
    int rh = getHeight(root->right);
    if (rh == INT_MIN) {
        return INT_MIN;
    }
    
    if (abs(rh-lh) > 1) {
        return INT_MIN;
    }
    
    return 1 + std::max(rh, lh);
}

