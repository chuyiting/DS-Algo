//
//  BinaryTreeRightSideView.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/12.
//

#ifndef BinaryTreeRightSideView_hpp
#define BinaryTreeRightSideView_hpp

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

class BinaryTreeRightSideView {
public:
    std::vector<int> rightSideView(TreeNode* root);
};

#endif /* BinaryTreeRightSideView_hpp */
