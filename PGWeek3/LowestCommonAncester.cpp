//
//  LowestCommonAncester.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#include "LowestCommonAncester.hpp"
#include <algorithm>


TreeNode* LowestCommonAncester::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if (p->val > root->val && q->val > root->val)  {
        return lowestCommonAncestor(root->right, p, q);
    } else if (p->val < root->val &&  q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
    
}

bool LowestCommonAncester::findNodePath(TreeNode* root, TreeNode *p, std::vector<TreeNode*> &nodePath) {
    if (root == nullptr) return false;
    
    nodePath.push_back(root);
    if (root == p) {
        return true;
    }
    
    if (findNodePath(root->right, p, nodePath) || findNodePath(root->left, p, nodePath)) {
        return true;
    }
    nodePath.pop_back();
    return false;
    
}
