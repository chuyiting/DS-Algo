//
//  SetMatrixZeroes.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "SetMatrixZeroes.hpp"

void SetMatrixZeroes::setZeroes(std::vector<std::vector<int>>& matrix) {
    bool firstRow = matrix[0][0] == 0;
    bool firstCol = matrix[0][0] == 0;
    for (int i = 0; i < matrix.size() && !firstCol; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
        }
    }
    for (int i = 0; i < matrix[0].size() && !firstRow; i++) {
        if (matrix[0][i] == 0) {
            firstRow = true;
        }
    }
    
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < matrix[0].size(); i++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrix.size(); j++) {
                matrix[j][i] = 0;
            }
        }
    }
    
    if (firstCol) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
        
    if (firstRow) {
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[0][i] = 0;
        }
    }
}
