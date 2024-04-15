//
//  SerializeAndDeserializeBinaryTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#ifndef SerializeAndDeserializeBinaryTree_hpp
#define SerializeAndDeserializeBinaryTree_hpp

#include <stdio.h>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};

class SerializeAndDeserializeBinaryTree {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root);
    std::string serializePreorder(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) ;
    TreeNode* deserializePreorder(std::string data) ;
};
#endif /* SerializeAndDeserializeBinaryTree_hpp */
