//
//  LowestCommonAncester.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/11.
//

#ifndef LowestCommonAncester_hpp
#define LowestCommonAncester_hpp

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


class LowestCommonAncester {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    
    bool findNodePath(TreeNode* root, TreeNode *p, std::vector<TreeNode*> &nodePath);
};

#endif /* LowestCommonAncester_hpp */
