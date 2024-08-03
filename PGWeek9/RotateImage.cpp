//
//  RotateImage.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "RotateImage.hpp"

// (i, j) -> (j, n-1-i)
void RotateImage::rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = n/2;
    for (int i = 0; i < m; i++){
        for (int j = i; j < n-i-1; j++) {
            int tmp1 = matrix[i][j];
            int tmp2 = matrix[j][n-1-i];
            int tmp3 = matrix[n-1-i][n-1-j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = tmp3;
            matrix[n-1-i][n-1-j] = tmp2;
            matrix[j][n-1-i] = tmp1;

        }
    }
    
    
}
