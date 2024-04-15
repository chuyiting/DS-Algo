//
//  ConstructTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#ifndef ConstructTree_hpp
#define ConstructTree_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class ConstructTree {
    std::unordered_map<int, int> iot; // <val, id>
    std::unordered_map<int, int> pot; // <val, id>
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    
    TreeNode* buildTreeFrom(std::vector<int>& preorder, int pbegin, int pend, std::vector<int>& inorder, int ibegin, int iend);
};

#endif /* ConstructTree_hpp */
