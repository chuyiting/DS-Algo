//
//  ValidateBinarySearchTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/14.
//

#include "ValidateBinarySearchTree.hpp"
#include <utility>
#include <vector>

bool ValidateBinarySearchTree::isValidBST(TreeNode* root) {
    std::vector<int> iot;
    this->inOrderTraversal(root, iot);
    for (int i = 1; i < iot.size(); i++) {
        if (iot[i] <= iot[i-1]) return false;
    }
    return true;
}

void ValidateBinarySearchTree::inOrderTraversal(TreeNode *root, std::vector<int> &result) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->val);
    inOrderTraversal(root->right, result);
}

bool checkBSTValidity(TreeNode *root, double leftB, double rightB) {
    if (root == nullptr) return true;
    if (root->val <= leftB || root->val >= rightB) return false;
    return checkBSTValidity(root->right, root->val, rightB) && checkBSTValidity(root->left, leftB, root->val);
}
