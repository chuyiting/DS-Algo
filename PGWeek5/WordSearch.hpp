//
//  WordSearch.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef WordSearch_hpp
#define WordSearch_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>

class WordSearch {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    bool dfs(std::vector<std::vector<char>>& board, int r, int c, std::vector<std::vector<bool>> &visited, std::string word, int id);
};

#endif /* WordSearch_hpp */
