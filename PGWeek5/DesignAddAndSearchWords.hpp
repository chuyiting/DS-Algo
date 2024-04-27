//
//  DesignAddAndSearchWords.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef DesignAddAndSearchWords_hpp
#define DesignAddAndSearchWords_hpp

#include <stdio.h>
#include <string>
#include <vector>

class TrieNode {
public:
    std::vector<TrieNode*> next;
    bool terminate;
    TrieNode() : next(26, nullptr), terminate(false) {};
    TrieNode(bool terminate) : next(26, nullptr), terminate(terminate) {};
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string word)  {
        TrieNode *curr = root;
        for (const auto &c : word) {
            if(curr->next[c-'a'] == nullptr) {
                curr->next[c-'a'] = new TrieNode();
            }
            curr = curr->next[c-'a'];
        }
        curr->terminate = true;
    }
    
    bool search(std::string word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(std::string word, int id, TrieNode *curr) {
        if (id == word.size()-1) {
            if (word[id] == '.') {
                for (auto *n : curr->next) {
                    if (n != nullptr && n->terminate) return true;
                }
                return false;
            } else {
                return curr->next[word[id] - 'a'] != nullptr && curr->next[word[id] - 'a']->terminate;
            }
        }
        
        if (word[id] == '.') {
            for (auto *n : curr->next) {
                if (n != nullptr && searchHelper(word, id+1, n)) {
                    return true;
                }
            }
            return false;
        }
        
        if (curr->next[word[id] - 'a'] == nullptr) return false;
        return searchHelper(word, id+1, curr->next[word[id] - 'a']);
    }
};

#endif /* DesignAddAndSearchWords_hpp */
