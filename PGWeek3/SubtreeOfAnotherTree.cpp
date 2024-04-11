//
//  SubtreeOfAnotherTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#include "SubtreeOfAnotherTree.hpp"

bool SubtreeOfAnotherTree::isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr || subRoot == nullptr) return root == subRoot;
    
    if (root->val == subRoot->val && isSameTree(root->right, subRoot->right) && isSameTree(root->left, subRoot->left) ) {
        return true;
    }
     
    return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
}

bool SubtreeOfAnotherTree::isSameTree(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr || root2 == nullptr) return root1 == root2;
    return root1->val == root2->val && isSameTree(root1->right, root2->right) && isSameTree(root1->left, root2->left);
}
