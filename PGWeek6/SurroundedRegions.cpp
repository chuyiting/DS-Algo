//
//  SurroundedRegions.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/30.
//

#include "SurroundedRegions.hpp"

void SurroundedRegions::solve(std::vector<std::vector<char>>& board) {
    std::vector<std::vector<bool>> shouldNotFlip(board.size(), std::vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
        dfs(board, shouldNotFlip, i, 0);
        dfs(board, shouldNotFlip, i, board[0].size()-1);
    }
    
    for (int j = 0; j < board[0].size(); j++) {
        dfs(board, shouldNotFlip, 0, j);
        dfs(board, shouldNotFlip, board.size()-1, j);
    }
    
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            if (!shouldNotFlip[r][c]) {
                board[r][c] = 'X';
            }
        }
    }
}

void SurroundedRegions::dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, int r, int c) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] == 'X') {
        return;
    }
    
    visited[r][c] = true;
    dfs(board, visited, r+1, c);
    dfs(board, visited, r-1, c);
    dfs(board, visited, r, c+1);
    dfs(board, visited, r, c-1);
}
