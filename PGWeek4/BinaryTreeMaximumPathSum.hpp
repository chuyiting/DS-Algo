//
//  BinaryTreeMaximumPathSum.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#ifndef BinaryTreeMaximumPathSum_hpp
#define BinaryTreeMaximumPathSum_hpp

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

class BinaryTreeMaximumPathSum {
    int sol = INT_MIN;
public:
    int maxPathSum(TreeNode* root);
    int maxPathSumWithRoot(TreeNode* root);
};

#endif /* BinaryTreeMaximumPathSum_hpp */
