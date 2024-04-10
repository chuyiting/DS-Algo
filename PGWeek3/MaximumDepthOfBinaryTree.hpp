//
//  MaximumDepthOfBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#ifndef MaximumDepthOfBinaryTree_hpp
#define MaximumDepthOfBinaryTree_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode* root);
};

#endif /* MaximumDepthOfBinaryTree_hpp */
