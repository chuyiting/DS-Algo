//
//  KthSmallestInBST.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/14.
//

#include "KthSmallestInBST.hpp"
#include <stack>

int KthSmallestInBST::kthSmallest(TreeNode* root, int k) {
    int result = -1, count = 0;
    kthSmallestHelper(root, k, count, result);
    return result;
}


int KthSmallestInBST::kthSmallest2(TreeNode* root, int k) {
    std::stack<TreeNode*> stack;
    auto *curr = root;
    int count = 0;
    
    while (!stack.empty() || curr != nullptr) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        
        curr = stack.top();
        stack.pop();
        count++;
        if (count == k) return curr->val;
        
        curr = curr->right;
        
    }
    return -1;
    
}

bool KthSmallestInBST::kthSmallestHelper(TreeNode* root, int k, int &count, int &result) {
    if (root == nullptr) {
        return false;
    }
    if (kthSmallestHelper(root->left, k, count, result)) return true;
    if (k == count+1) {
        result = root->val;
        return true;
    }
    count++;
    if (kthSmallestHelper(root->right, k, count, result)) return true;
    
    return false;
    
}
