//
//  SameTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#ifndef SameTree_hpp
#define SameTree_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class SameTree {
    bool isSameTree(TreeNode* p, TreeNode* q);
};


#endif /* SameTree_hpp */
