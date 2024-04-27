//
//  ImplementTrie.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef ImplementTrie_hpp
#define ImplementTrie_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    bool terminate;
    bool root;
    std::unordered_map<char, TrieNode*> next;
    TrieNode() : terminate(false), root(true) {};
    TrieNode(bool terminate) : terminate(terminate), root(false) {};
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        auto *curr = root;
        for (int i = 0; i < word.size();  i++) {
            if (curr->next.count(word[i]) == 0) {
                curr->next[word[i]] = new TrieNode(false);
            }
            
            curr = curr->next[word[i]];
            
            if (i == word.size()-1) {
                curr->terminate = true;
            }
        }
    }
    
    bool search(std::string word) {
        auto *curr = root;
        for (int i = 0; i < word.size();  i++) {
            if (curr->next.count(word[i]) == 0) {
                return false;
            }
            curr = curr->next[word[i]];
            
            if (i == word.size()-1) {
                return curr->terminate;
            }
        }
        return false;
    }
    
    bool startsWith(std::string prefix) {
        auto *curr = root;
        for (int i = 0; i < prefix.size();  i++) {
            if (curr->next.count(prefix[i]) == 0) {
                return false;
            }
            curr = curr->next[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif /* ImplementTrie_hpp */
