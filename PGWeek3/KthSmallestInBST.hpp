//
//  KthSmallestInBST.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/14.
//

#ifndef KthSmallestInBST_hpp
#define KthSmallestInBST_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class KthSmallestInBST {
public:
    int kthSmallest(TreeNode* root, int k);
    int kthSmallest2(TreeNode* root, int k);
    bool kthSmallestHelper(TreeNode* root, int k, int &count, int &result);
};

#endif /* KthSmallestInBST_hpp */
