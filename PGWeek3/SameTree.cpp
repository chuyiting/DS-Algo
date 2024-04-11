//
//  SameTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#include "SameTree.hpp"

bool SameTree::isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr) return p == q;
    return p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    
}
