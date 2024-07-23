//
//  ForeignDictionary.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/10.
//

#include "ForeignDictionary.hpp"
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

std::pair<char, char> findFirstDiffChar(std::string s1, std::string s2) {
    int l = std::min(s1.size(), s2.size());
    for (int i = 0; i < l; i++) {
        if (s1[i] != s2[i]) {
            return {s1[i], s2[i]};
        }
    }
    
    if (s1.size() < s2.size()) {
        return {'\0', s2[l]};
    } else if (s1.size() > s2.size()) {
        return {s1[l], '\0'};
    } else {
        return {'\0', '\0'};
    }
    
}


std::string ForeignDictionary::foreignDictionary(std::vector<std::string>& words) {
    std::unordered_map<char, std::vector<char>> graph;
    std::unordered_map<char, int> inDegree;
    
    for (int i = 0; i < words.size(); i++) {
        for (int j = i+1; j < words.size(); j++) {
            auto diff = findFirstDiffChar(words[i], words[j]);
            if (diff.first != '\0' && diff.second == '\0') {
                return "";
            }
            if (diff.first != '\0' && diff.second != '\0') {
                if (graph.count(diff.first) == 0) {
                    graph[diff.first] = {diff.second};
                } else {
                    graph[diff.first].push_back(diff.second);
                }
                inDegree[diff.second]++;
                if (inDegree.count(diff.first) == 0) inDegree[diff.first] = 0;
            }
        }
    }
    
    for (const auto &word: words) {
        for (int i = 0; i < word.size(); i++) {
            if (inDegree.count(word[i]) == 0) {
                inDegree[word[i]] = 0;
            }
        }
    }
    
    std::string sol = "";
    std::stack<char> stack;
    for (auto it = inDegree.begin(); it != inDegree.end(); it++) {
        if (it->second == 0) {
            stack.push(it->first);
        }
    }
    
    while (!stack.empty()) {
        char c = stack.top();
        sol += c;
        stack.pop();
        for (auto nxt : graph[c]) {
            inDegree[nxt]--;
            if (inDegree[nxt] == 0) {
                stack.push(nxt);
            }
        }
    }
    
    if (sol.length() == inDegree.size()) return sol;
    return "";
 
}

