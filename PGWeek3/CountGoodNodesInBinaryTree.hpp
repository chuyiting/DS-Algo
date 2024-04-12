//
//  CountGoodNodesInBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#ifndef CountGoodNodesInBinaryTree_hpp
#define CountGoodNodesInBinaryTree_hpp

#include <stdio.h>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class CountGoodNodesInBinaryTree {
    int currMax = INT_MIN;
public:
    int goodNodes(TreeNode* root);
};

#endif /* CountGoodNodesInBinaryTree_hpp */
