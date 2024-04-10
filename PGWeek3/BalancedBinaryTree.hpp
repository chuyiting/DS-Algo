//
//  BalancedBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#ifndef BalancedBinaryTree_hpp
#define BalancedBinaryTree_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode* root);
    int getHeight(TreeNode *root);
};

#endif /* BalancedBinaryTree_hpp */
