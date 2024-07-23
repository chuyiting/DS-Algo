//
//  WordBreak.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/16.
//

#include "WordBreak.hpp"
#include <vector>


class TrieNode {
    TrieNode* childNode[26];
    
    bool isEnd;
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
        isEnd = false;
    }
    
    void insert(std::string word) {
        TrieNode *curr = this;
        for (const auto &c : word) {
            if (curr->childNode[c-'a'] == nullptr) {
                curr->childNode[c-'a'] = new TrieNode();
            }
            curr = curr->childNode[c-'a'];
        }
        curr->isEnd = true;
    }
    
    std::vector<int> findInitialMatch(std::string s) {
        std::vector<int> sol;
        TrieNode *curr = this;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (curr->childNode[c-'a'] == nullptr) {
                return sol;
            } else {
                curr = curr->childNode[c-'a'];
                if (curr->isEnd) {
                    sol.push_back(i+1);
                }
            }
        }
        return sol;
    }
};



bool WordBreak::wordBreak(std::string s, std::vector<std::string>& wordDict) {
    TrieNode *trie = new TrieNode();
    for (auto &word : wordDict) {
        trie->insert(word);
    }
    
    std::vector<bool> canBreak(s.size()+1, false);
    canBreak[s.size()] = true;
    for (int i = s.size()-1; i >= 0; i--) {
        std::string str = s.substr(i, s.size()-i);
        auto list = trie->findInitialMatch(str);
        if (list.size() == 0) {
            continue;
        } else {
            for (auto& nxtId : list) {
                if (canBreak[nxtId+i]) {
                    canBreak[i] = true;
                    continue;
                }
            }
        }
        
    }
    return canBreak[0];
    
}

