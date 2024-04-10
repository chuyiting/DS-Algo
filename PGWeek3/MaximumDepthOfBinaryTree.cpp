//
//  MaximumDepthOfBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#include "MaximumDepthOfBinaryTree.hpp"
#include <algorithm>

int MaximumDepthOfBinaryTree::maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(maxDepth(root->right), maxDepth(root->left));
}
