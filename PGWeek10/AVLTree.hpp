//
//  AVLTree.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/24.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>

/*
 AVL tree is more balanced than red-black tree, but requires more rotation
 If your application involves more searching, use AVL tree
 If your application involves more insertion and deletion, use red-black tree
 */
struct Node {
    int value;
    Node *left;
    Node *right;
    size_t height;
    
    Node (int val) {
        this->value = val;
        this->height = 1;
    }
    
    Node (int val, Node *left, Node *right) {
        this->value = val;
        this->left = left;
        this->right = right;
        this->height = 1 + std::max(this->getHeight(left), this->getHeight(right));
    }
    
    static size_t getHeight(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }
    
    static int getBalance(Node *left, Node *right) {
        return getHeight(left) - getHeight(right);
    }
    
    static int getBalanceFor(Node *root) {
        return getHeight(root->left) - getHeight(root->right);
    }
    
    static Node *leftRotate(Node *root) {
        Node *y = root->right;
        root->right = y->left;
        y->left = root;
        
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        return y;
    }
    
    static Node *rightRotate(Node *root) {
        Node *x = root->left;
        root->left = x->right;
        x->right = root;
        
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        return x;
    }
    
    static void preOrder (Node *node) {
        if (node != nullptr) {
            std::cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

Node *insert(Node *node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    
    if (val < node->value) {
        node ->left = insert(node->left, val);
    } else if (val > node->value) {
        node ->right = insert(node->right, val);
    } else {
        return node;
    }
    
    node -> height = 1 + std::max(Node::getHeight(node->left), Node::getHeight(node->right));
    
    int balance = Node::getBalance(node->left, node->right);
    if (balance > 1 && val < node->left->value) { // Left Left Case
        return Node::rightRotate(node);
    }
    
    if (balance > 1  && val > node->left->value) { // Left Right Case
        node->left = Node::leftRotate(node->left);
        return Node::rightRotate(node);
    }
    
    if (balance < -1 && val > node->right->value) { // Right Right case
        return Node::leftRotate(node);
    }
    
    if (balance < -1 && val < node->right->value) {  //  Right Left case
        node -> right = Node::rightRotate(node->right);
        return Node::leftRotate(node);
    }
    
    return node;
}

// first perform normal BST deletion, and then search all the way up
// Rebalance nodes along the path if necessarry
// The choice of left and right children is by the height (larger one)
// Balancind rule is the same as insertion
Node *deleteNode(Node *node, int val) {
    if (node == nullptr) return node;
    
    if (node->value > val) {
        node->left = deleteNode(node->left, val);
    } else if (node->value < val) {
        node->right = deleteNode(node->right, val);
    } else {
        if (node->right == nullptr) {
            node = node->left;
        } else if (node->left == nullptr) {
            node = node->right;
        } else {
            Node *curr = node->right;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            node->value = curr->value;
            node->right = deleteNode(node->right, curr->value);
        }
    }
    
    if (node == nullptr) return node;
    
    node->height = 1 + std::max(Node::getHeight(node->left), Node::getHeight(node->right));
    
    int balance = Node::getBalance(node->left, node->right);
    if (balance > 1 && Node::getBalanceFor(node->left) > 0) { // Left Left Case
        return Node::rightRotate(node);
    }
    
    if (balance > 1  && Node::getBalanceFor(node->left) < 0) { // Left Right Case
        node->left = Node::leftRotate(node->left);
        return Node::rightRotate(node);
    }
    
    if (balance < -1 && Node::getBalanceFor(node->right) < 0) { // Right Right case
        return Node::leftRotate(node);
    }
    
    if (balance < -1 && Node::getBalanceFor(node->right) > 0) {  //  Right Left case
        node -> right = Node::rightRotate(node->right);
        return Node::leftRotate(node);
    }
    
    return node;
}



#endif /* AVLTree_hpp */
