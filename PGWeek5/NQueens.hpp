//
//  NQueens.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/27.
//

#ifndef NQueens_hpp
#define NQueens_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>

class NQueens {
    std::vector<std::vector<std::string>> sol;
public:
    std::vector<std::vector<std::string>> solveNQueens(int n);
    std::vector<std::string> formatSol (int n, std::vector<int> output);
    void helper(int n, int row, std::vector<int> &curr, std::unordered_set<int> &columnAttack, std::unordered_set<int> &diagAttack1, std::unordered_set<int> &diagAttack2);
    
    std::vector<std::vector<std::string>> solveNQueensBit(int n);
    void helperBit(int n, int row, std::vector<std::string> &curr, int columnAttack, int diagAttack1, int diagAttack2);
};

#endif /* NQueens_hpp */
