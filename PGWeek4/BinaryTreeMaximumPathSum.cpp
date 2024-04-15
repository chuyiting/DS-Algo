//
//  BinaryTreeMaximumPathSum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#include "BinaryTreeMaximumPathSum.hpp"
#include <algorithm>

int BinaryTreeMaximumPathSum::maxPathSum(TreeNode* root) {
    this->maxPathSumWithRoot(root);
    return this->sol;
    
}

int BinaryTreeMaximumPathSum::maxPathSumWithRoot(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    
    int lmax = std::max(0, maxPathSumWithRoot(root->left));
    int rmax = std::max(0, maxPathSumWithRoot(root->right));
    int maxWithRoot = lmax + rmax + root->val;
    this->sol = std::max(this->sol, maxWithRoot);
    return std::max(root->val+lmax, root->val+rmax);
}
