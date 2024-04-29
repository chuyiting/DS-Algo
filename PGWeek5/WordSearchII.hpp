//
//  WordSearchII.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef WordSearchII_hpp
#define WordSearchII_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> next;
    bool isWord;
    int ref = 0;
    TrieNode() : isWord(false) {};
    TrieNode(bool isWord) : isWord(isWord) {};
    void addWord(std::string word) {
        ref++;
        auto *curr = this;
        for (const auto&c : word) {
            if (curr->next[c] == nullptr) {
                curr->next[c] = new TrieNode();
            }
            curr = curr->next[c];
            curr->ref++;
        }
        curr->isWord = true;
    }
    
    void deleteWord(std::string word) {
        auto *curr = this;
        curr->ref--;
        for (const auto&c : word) {
            auto *next = curr->next[c];
            next->ref--;
            curr = next;
        }
        curr->isWord = false;
    }
};


class Solution {
    std::vector<std::string> sol;
    std::vector<std::vector<bool>> visited;
    TrieNode *root;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        visited.resize(board.size(), std::vector<bool>(board[0].size(), false));
        this->root = this->constructTrie(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size();j++) {
                std::string curr = "";
                findWordsHelper(board, this->root, i, j, curr);
            }
        }
        
        return sol;
    }
    
    void findWordsHelper(std::vector<std::vector<char>>& board, TrieNode *curr, int r, int c, std::string &word){
        if (curr->isWord && curr->ref > 0) {
            this->sol.push_back(word);
            this->root->deleteWord(word);
        }
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || curr->ref == 0) {
            return;
        }
        
        if (curr->next.count(board[r][c]) != 0) {
            visited[r][c] = true;
            word += board[r][c];
            auto *next = curr->next[board[r][c]];
            findWordsHelper(board, next, r+1, c, word);
            findWordsHelper(board, next, r-1, c, word);
            findWordsHelper(board, next, r, c+1, word);
            findWordsHelper(board, next, r, c-1, word);
            word = word.substr(0, word.size()-1);
            visited[r][c] = false;
        }
        
    }
    
    
    TrieNode *constructTrie(std::vector<std::string>& words) {
        auto *root = new TrieNode();
        for (const auto &word : words) {
            root->addWord(word);
        }
        return root;
    }
    
    void removeWord(std::string word) {
        
    }
};

#endif /* WordSearchII_hpp */
