//
//  InvertBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#ifndef InvertBinaryTree_hpp
#define InvertBinaryTree_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class InvertBinaryTree {
public:
    TreeNode* invertTree(TreeNode* root);
};

#endif /* InvertBinaryTree_hpp */
