//
//  LadderLength.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/5/6.
//

#include "LadderLength.hpp"
#include <queue>

int LadderLength::ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (const auto &word : wordList) {
        graph[word] = {};
    }

    int notIncludeBegin = 0;
    if (graph.count(beginWord) == 0) {
        graph[beginWord] = {};
        wordList.push_back(beginWord);
        notIncludeBegin = 1;
    }

    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i+1; j < wordList.size(); j++) {
            if (canTransform(wordList[i], wordList[j])) {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
    std::unordered_set<std::string> visited;
    int ans = getMinDistance(graph, visited, beginWord, endWord);

    if (ans == 0) return 0;
    return ans - notIncludeBegin;
}

bool LadderLength::canTransform(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) return false;
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            count++;
        }
        if (count > 1) return false;
    }
    return true;
}

int LadderLength::getMinDistance(std::unordered_map<std::string, std::vector<std::string>> &graph, std::unordered_set<std::string> &visited, std::string begin, std::string end) {
    
    std::queue<std::string> q;
    q.push(begin);
    
    int d = 0;
    while (!q.empty()) {
        int n = q.size();
        d++;
        for (int i = 0; i < n; i++) {
            if (q.front() == end) break;
            if (visited.count(q.front()) != 0) continue;
            for (const auto &nxt : graph[q.front()]) {
                q.push(nxt);
            }
            visited.insert(q.front());
            q.pop();
        }
    }

    return d;
}

int LadderLength::ladderLength2(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    wordList.push_back(beginWord);
    for (const auto &word : wordList) {
        for (int i = 0; i < word.size(); i++) {
            std::string cpy = word;
            cpy[i] = '*';
            if (graph.count(cpy) == 0) {
                graph[cpy] = {};
            }
            graph[cpy].push_back(word);
        }
    }
    
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;
    q.push(beginWord);
    int d = 0;
    
    while (!q.empty()) {
        int currLevelSize = q.size();
        d++;
        for (int j = 0; j < currLevelSize; j++) {
            auto curr = q.front();
            q.pop();
            visited.insert(curr);
            for (int i = 0; i < curr.size(); i++) {
                auto cpy = curr;
                cpy[i] = '*';
                for (const auto &next : graph[cpy]) {
                    if (visited.count(next) != 0) continue;
                    if (next == endWord) return d+1;
                    q.push(next);
                }
            }
        }
    }
    
    return 0;
}
