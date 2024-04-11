//
//  SubtreeOfAnotherTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#ifndef SubtreeOfAnotherTree_hpp
#define SubtreeOfAnotherTree_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class SubtreeOfAnotherTree {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot);
    bool isSameTree(TreeNode* root1, TreeNode* root2);
};

#endif /* SubtreeOfAnotherTree_hpp */
