//
//  HuffmanCode.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/6.
//

#ifndef HuffmanCode_hpp
#define HuffmanCode_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

struct MinHeapNode {
    char symbol;
    int freq;
    
    MinHeapNode *left, *right;
    MinHeapNode(char symbol, int freq) {
        this->symbol = symbol;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    MinHeapNode(char symbol, int freq, MinHeapNode *l, MinHeapNode *r) {
        this->symbol = symbol;
        this->freq = freq;
        this->left = l;
        this->right = r;
    }
};

class HuffmanCode {
public:
    MinHeapNode *buildHuffmanTree(std::vector<char> data, std::vector<int> freq);
    std::unordered_map<char, std::string> huffmanCode(MinHeapNode *huffmanTree);
    void huffmanCodeHelper(MinHeapNode *curr, std::string accum, std::unordered_map<char, std::string>& result);
};

#endif /* HuffmanCode_hpp */
