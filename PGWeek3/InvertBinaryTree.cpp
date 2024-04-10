//
//  InvertBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#include "InvertBinaryTree.hpp"

TreeNode* InvertBinaryTree::invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    auto *newRight = invertTree(root->left);
    auto *newLeft = invertTree(root->right);
    
    root->left = newLeft;
    root->right = newRight;
    return root;
}
