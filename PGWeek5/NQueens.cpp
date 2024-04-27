//
//  NQueens.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#include "NQueens.hpp"

std::vector<std::vector<std::string>> NQueens::solveNQueens(int n) {
    std::vector<int> curr;
    std::unordered_set<int> columnAttack;
    std::unordered_set<int> diagAttack1;
    std::unordered_set<int> diagAttack2;
    
    this->helper(n, 0, curr, columnAttack, diagAttack1, diagAttack2);
    return this->sol;
}

std::vector<std::string> NQueens::formatSol (int n, std::vector<int> output) {
    std::vector<std::string> result;
    for (int i = 0; i < n; i++) {
        std::string row = "";
        for (int j = 0; j < n; j++) {
            if (j == output[i]) {
                row += 'Q';
            } else {
                row += '.';
            }
        }
        result.push_back(row);
    }
    return result;
}

void NQueens::helper(int n, int row, std::vector<int> &curr, std::unordered_set<int> &columnAttack, std::unordered_set<int> &diagAttack1, std::unordered_set<int> &diagAttack2) {
    if (row >= n) {
        this->sol.push_back(this->formatSol(n, curr));
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (columnAttack.count(i)!= 0) continue;
        if (diagAttack1.count(row+i) != 0) continue;
        if (diagAttack2.count(row-i) != 0) continue;
        columnAttack.insert(i);
        diagAttack1.insert(row+i);
        diagAttack2.insert(row-i);
        curr.push_back(i);
        helper(n, row+1, curr, columnAttack, diagAttack1, diagAttack2);
        columnAttack.erase(i);
        diagAttack1.erase(row+i);
        diagAttack2.erase(row-i);
        curr.pop_back();
    }
}

std::vector<std::vector<std::string>> NQueens::solveNQueensBit(int n) {
    std::vector<std::string> curr;
    this->helperBit(n, 0, curr, 0, 0, 0);
    return this->sol;
}

void NQueens::helperBit(int n, int row, std::vector<std::string> &curr, int columnAttack, int diagAttack1, int diagAttack2) {
    if (row >= n) {
        this->sol.push_back(curr);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (columnAttack & (1 << i) || diagAttack1 & (1 << (i+row)) || (diagAttack2 & (1 << (i-row+n-1)))) {
            continue;
        }
        columnAttack |= (1 << i);
        diagAttack1 |= (1 << (i+row));
        diagAttack2 |= (1 << (i-row+n-1));
        curr[row][i] = 'Q';
        helperBit(n, row+1, curr, columnAttack, diagAttack1, diagAttack2);
        columnAttack &= ~(1 << i);
        diagAttack1 &= ~(1 << (i+row));
        diagAttack2 &= ~(1 << (i-row+n-1));
        curr[row][i] = '.';
    }
}
