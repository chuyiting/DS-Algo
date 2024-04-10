//
//  DiameterOfBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/10.
//

#ifndef DiameterOfBinaryTree_hpp
#define DiameterOfBinaryTree_hpp

#include <stdio.h>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class DiameterOfBinaryTree {
    std::unordered_map<TreeNode*, int> heights;
    int sol = 0;
public:
    int diameterOfBinaryTree(TreeNode* root);
    int getHeight(TreeNode *root);
};

#endif /* DiameterOfBinaryTree_hpp */
