//
//  ConstructTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#include "ConstructTree.hpp"

TreeNode* ConstructTree::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    for (int i = 0; i < preorder.size(); i++) {
        iot[inorder[i]] = i;
    }
    return buildTreeFrom(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

TreeNode* ConstructTree::buildTreeFrom(std::vector<int>& preorder, int pbegin, int pend, std::vector<int>& inorder, int ibegin, int iend) {
    if (pbegin == pend) return new TreeNode(preorder[pbegin]);
    if (pend < pbegin) return nullptr;
    
    TreeNode *root = new TreeNode(preorder[pbegin]);
    int rootIotId = this->iot[root->val];
    int leftTreeSize = rootIotId - ibegin;
    int rightTreeSize = iend - rootIotId;
    
    if (leftTreeSize > 0) {
        root->left = buildTreeFrom(preorder, pbegin+1, pbegin+leftTreeSize, inorder, ibegin, rootIotId-1);
    }
    
    if (rightTreeSize > 0) {
        root->right = buildTreeFrom(preorder, pbegin+leftTreeSize+1, pend, inorder, rootIotId+1, iend);
    }
    
    return root;
    
}
