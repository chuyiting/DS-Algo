//
//  ValidSudoku.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/29.
//

#include "ValidSudoku.hpp"
#include <unordered_set>

bool ValidSudoku::isValidSudoku(std::vector<std::vector<char>>& board) {
    // check row
    for (const auto& row: board) {
        std::unordered_set<char> visited;
        for (const auto &num : row) {
            if (num == '.') continue;;
            if (visited.find(num) != visited.end()) return false;
            visited.insert(num);
        }
    }
    
    // check column
    for (int colId = 0; colId < 9; colId++) {
        std::unordered_set<char> visited;
        for (int i = 0; i < 9; i++) {
            auto num = board[i][colId];
            if (num == '.') continue;;
            if (visited.find(num) != visited.end()) return false;
            visited.insert(num);
        }
    }
    
    // check grid
    for (int i = 0; i < 9; i++) {
        int rowOffset = i / 3;
        int colOffset = i % 3;
        std::unordered_set<char> visited;
        for (int j = 0; j < 9; j++) {
            auto num = board[j/3 + rowOffset*3][j%3 + colOffset*3];
            if (num == '.') continue;;
            if (visited.find(num) != visited.end()) return false;
            visited.insert(num);
        }
    }
    return true;
}
