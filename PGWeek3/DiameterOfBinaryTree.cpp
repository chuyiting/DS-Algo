//
//  DiameterOfBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#include "DiameterOfBinaryTree.hpp"
#include <algorithm>

int DiameterOfBinaryTree::diameterOfBinaryTree(TreeNode* root) {
    this->getHeight(root);
    return this->sol;
}

int DiameterOfBinaryTree::getHeight(TreeNode *root) {
    if (root == nullptr) return -1;
    int rh = this->getHeight(root->right);
    int lh = this->getHeight(root->left);
    int h = 1 + std::max(rh, lh);
    this->sol = std::max(this->sol, rh + lh +2);
    return h;
}
