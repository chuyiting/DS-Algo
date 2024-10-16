//
//  HuffmanCode.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/6.
//

#include "HuffmanCode.hpp"
#include <queue>
#include <iostream>

struct compare {
    bool operator() (MinHeapNode *l, MinHeapNode *r) {
        return l->freq > r->freq;
    }
};

MinHeapNode *HuffmanCode::buildHuffmanTree(std::vector<char> data, std::vector<int> freq) {
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;
    
    for(int i = 0; i < data.size(); i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    
    while (minHeap.size() > 1) {
        auto *l = minHeap.top();
        minHeap.pop();
        
        auto *r = minHeap.top();
        minHeap.pop();
        
        minHeap.push(new MinHeapNode('&', l->freq+r->freq, l, r));
    }
    
    return minHeap.top();
}

std::unordered_map<char, std::string> HuffmanCode::huffmanCode(MinHeapNode *huffmanTree) {
    std::unordered_map<char, std::string> result;
    huffmanCodeHelper(huffmanTree, "", result);
    return result;
}

void HuffmanCode::huffmanCodeHelper(MinHeapNode *curr, std::string accum, std::unordered_map<char, std::string>& result) {
    if (curr == nullptr) return;
    
    if (curr->left == nullptr && curr->right == nullptr) {
        std::cout << curr->symbol << ": " << accum << std::endl;
        result[curr->symbol] = accum;
        return;
    }
    
    huffmanCodeHelper(curr->left, '0' + accum, result);
    huffmanCodeHelper(curr->right, '1' + accum, result);
}
