//
//  LadderLength.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/5/6.
//

#ifndef LadderLength_hpp
#define LadderLength_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class LadderLength {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
    
    int ladderLength2(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
    
    bool canTransform(std::string s1, std::string s2);
    
    int getMinDistance(std::unordered_map<std::string, std::vector<std::string>> &graph, std::unordered_set<std::string> &visited, std::string begin, std::string end);
};

#endif /* LadderLength_hpp */
