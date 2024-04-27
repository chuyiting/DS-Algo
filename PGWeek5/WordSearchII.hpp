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
    std::string word;
    TrieNode() : isWord(false) {};
    TrieNode(bool isWord) : isWord(isWord) {};
};


class WordSearchII {
    std::unordered_set<std::string> sol;
    std::vector<std::vector<bool>> visited;
    TrieNode *root;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        visited.resize(board.size(), std::vector<bool>(board[0].size(), false));
        this->root = this->constructTrie(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size();j++) {
                findWordsHelper(board, this->root, i, j);
            }
        }
        
        std::vector<std::string> ans;
        ans.insert(ans.end(), sol.begin(), sol.end());
        return ans;
    }
    
    void findWordsHelper(std::vector<std::vector<char>>& board, TrieNode *curr, int r, int c){
        if (curr->isWord) {
            this->sol.insert(curr->word);
        }
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c]) {
            return;
        }
        
        if (curr->next.count(board[r][c]) != 0) {
            visited[r][c] = true;
            auto *next = curr->next[board[r][c]];
            findWordsHelper(board, next, r+1, c);
            findWordsHelper(board, next, r-1, c);
            findWordsHelper(board, next, r, c+1);
            findWordsHelper(board, next, r, c-1);
            visited[r][c] = false;
        }
        
    }
    
    
    TrieNode *constructTrie(std::vector<std::string>& words) {
        auto *root = new TrieNode();
        for (const auto &word : words) {
            auto *curr = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                if (curr->next.count(c) == 0) {
                     curr->next[c] = new TrieNode();
                }
                curr = curr->next[c];
                if (i == word.size()-1) {
                    curr->isWord = true;
                    curr->word = word;
                }
            }
        }
        return root;
    }
    
    void removeWord(std::string word) {
        
    }
};

#endif /* WordSearchII_hpp */
