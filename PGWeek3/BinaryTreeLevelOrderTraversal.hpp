//
//  BinaryTreeLevelOrderTraversal.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#ifndef BinaryTreeLevelOrderTraversal_hpp
#define BinaryTreeLevelOrderTraversal_hpp

#include <stdio.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class BinaryTreeLevelOrderTraversal {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root);
};

#endif /* BinaryTreeLevelOrderTraversal_hpp */
