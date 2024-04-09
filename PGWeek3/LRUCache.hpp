//
//  LRUCache.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/9.
//

#ifndef LRUCache_hpp
#define LRUCache_hpp

#include <stdio.h>
#include <list>
#include <unordered_map>

struct ListNode {
    int value;
    ListNode *prev;
    ListNode *next;
    ListNode() : value(0), next(nullptr), prev(nullptr) {};
    ListNode(int val) : value(val), next(nullptr), prev(nullptr) {};
    ListNode(int val, ListNode *next, ListNode *prev) : value(0), next(next), prev(prev) {};
};

class LRUCache {
    std::unordered_map<int, ListNode*> keys;
    ListNode *valueList = nullptr; // from lastest to least recently used
    ListNode *valueListBack = nullptr;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
        
    int get(int key) {
        if (!this->keys.count(key)) {
            return -1;
        }
        
        auto value = keys[key]->value;
        this->moveValueToFront(keys[key]);
        
        return value;
    }
        
    void put(int key, int value) {
        if (this->keys.count(key)) {
            this->keys[key]->value = value;
            this->moveValueToFront(keys[key]);
            return;
        }
        
        if (keys.size() == 0) {
            ListNode *node = new ListNode(value);
            this->valueList = node;
            this->valueListBack = node;
            this->keys[key] = node;
            return;
        }
        
        ListNode *node = new ListNode(value, this->valueList, nullptr);
        this->valueList -> prev = node;
        this->valueList = node;
        
        if (keys.size() > this->capacity) {
            this->valueListBack->prev->next = nullptr;
            this->valueListBack = this->valueListBack->prev;
        }
    }
    
    void moveValueToFront(ListNode *valNode) {
        auto *nextTmp = valNode->next;
        auto *prevTmp = valNode->prev;
        
        if (prevTmp == nullptr) {
            return;
        }
        
        if (valNode == this->valueListBack) {
            this->valueListBack = prevTmp;
        }
        
        prevTmp -> next = nextTmp;
        if (nextTmp != nullptr) {
            nextTmp -> prev = prevTmp;
        }
        
        valNode->next = valueList;
        valueList->prev = valNode;
        valNode->prev = nullptr;
        this->valueList = valNode;
    }
};

#endif /* LRUCache_hpp */
