//
//  ValidateBinarySearchTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/14.
//

#ifndef ValidateBinarySearchTree_hpp
#define ValidateBinarySearchTree_hpp

#include <stdio.h>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode* root);
    void inOrderTraversal(TreeNode *root, std::vector<int> &result);
};

#endif /* ValidateBinarySearchTree_hpp */
