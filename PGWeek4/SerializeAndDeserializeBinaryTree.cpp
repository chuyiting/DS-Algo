//
//  SerializeAndDeserializeBinaryTree.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/15.
//

#include "SerializeAndDeserializeBinaryTree.hpp"
#include<queue>
#include<sstream>
#include <string>
#include <vector>
#include <stack>

std::string SerializeAndDeserializeBinaryTree::serialize(TreeNode* root) {
    if (root == nullptr) return "";
    
    std::queue<TreeNode*> queue;
    queue.push(root);
    std::string sol = std::to_string(root->val) + ",";
    
    while (!queue.empty()) {
        int prevLevelSize = queue.size();
        for (int i = 0; i < prevLevelSize; i++) {
            TreeNode *prevNode = queue.front();
            queue.pop();
            if (prevNode->left != nullptr) {
                sol += std::to_string(prevNode->left->val) + ",";
                queue.push(prevNode->left);
            } else {
                sol += "-1001,";
            }
            
            if (prevNode->right != nullptr) {
                sol += std::to_string(prevNode->right->val) + ",";
                queue.push(prevNode->right);
            } else {
                sol += "-1001,";
            }
        }
        
    }
    
    return sol;
    
}

TreeNode* SerializeAndDeserializeBinaryTree::deserialize(std::string data) {
    if (data == "") return nullptr;
    std::stringstream ss(data);
    std::string token;
    
    std::getline(ss, token, ',');
    TreeNode *root = new TreeNode(std::stoi(token));
    std::queue<TreeNode *> prevLevel;
    prevLevel.push(root);
   
    while (std::getline(ss, token, ',')) {
        auto *curr = prevLevel.front();
        prevLevel.pop();
        std::string lcv = token, rcv;
        std::getline(ss, rcv, ',');
        if (lcv != "-1001") {
            auto *lc = new TreeNode(std::stoi(lcv));
            curr->left = lc;
            prevLevel.push(lc);
        }
        
        if (rcv != "-1001") {
            auto *rc = new TreeNode(std::stoi(rcv));
            curr->right = rc;
            prevLevel.push(rc);
        }
        
    }
    
    return root;
}


std::string serializePreorder(TreeNode* root) {
    if (root == nullptr) return "";
    std::stack<TreeNode*> stack;
    stack.push(root);
    std::string sol = std::to_string(root->val) + ",";
    
    while(!stack.empty()) {
        TreeNode *curr = stack.top();
        stack.pop();
        
        if (curr->left!= nullptr) {
            sol += std::to_string(curr->left->val) + ",";
            stack.push(curr->left);
        } else {
            sol += "null,";
        }
        
        if (curr->right!= nullptr) {
            sol += std::to_string(curr->right->val) + ",";
            stack.push(curr->right);
        } else {
            sol += "null,";
        }
    }
    
    return sol;
}

TreeNode* deserializePreorder(std::string data) {
    if (data == "") return nullptr;
    std::stringstream ss(data);
    std::string token;
    std::stack<TreeNode *> prevNodes;
    
    std::getline(ss, token, ',');
    TreeNode *root = new TreeNode(std::stoi(token));
    prevNodes.push(root);
    
    while (std::getline(ss, token, ',')) {
        TreeNode *curr = prevNodes.top();
        prevNodes.pop();
        
        std::string lcv = token, rcv;
        std::getline(ss, rcv, ',');
        if (lcv != "null") {
            curr->left = new TreeNode(std::stoi(lcv));
            prevNodes.push(curr->left);
        }
        
        if (rcv != "null") {
            curr->right = new TreeNode(std::stoi(rcv));
            prevNodes.push(curr->right);
        }
    }
    
    return root;
}
