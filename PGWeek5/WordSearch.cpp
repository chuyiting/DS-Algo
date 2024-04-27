//
//  WordSearch.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#include "WordSearch.hpp"

bool WordSearch::exist(std::vector<std::vector<char>>& board, std::string word) {
    int n = board.size(), m = board[0].size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(board, i, j, visited, word, 0)) return true;
        }
    }
    return false;
}

bool WordSearch::dfs(std::vector<std::vector<char>>& board, int r, int c, std::vector<std::vector<bool>> &visited, std::string word, int id) {
    if (id >= word.size()) return true;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
        return false;
    }
    
    if (visited[r][c]) return false;
    
    if (word[id] == board[r][c]) {
        visited[r][c] = true;
        if (dfs(board, r+1, c, visited, word, id+1)) return true;
        if (dfs(board, r, c+1, visited, word, id+1)) return true;
        if (dfs(board, r-1, c, visited, word, id+1)) return true;
        if (dfs(board, r, c-1, visited, word, id+1)) return true;
        visited[r][c] = false;
    }
    return false;
}
