//
//  SpiralMatrix.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "SpiralMatrix.hpp"

std::vector<int> SpiralMatrix::spiralOrder(std::vector<std::vector<int>>& matrix) {
    int l = 0, t = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    
    int r = n-1;
    int b = m-1;
    std::vector<int> sol;
    while (l <= r && t <= b) {
        for (int i = l; i <= r; i++) {
            sol.push_back(matrix[t][i]);
        }
        
        for (int i = t+1; i <= b; i++) {
            sol.push_back(matrix[i][r]);
        }
        
        for (int i = r-1; i >= l && b!=t; i--) {
            sol.push_back(matrix[b][i]);
        }
        
        for (int i = b-1; i > t && l !=r; i--) {
            sol.push_back(matrix[i][l]);
        }
        
        l++;
        t++;
        r = n-1-l;
        b = m-1-t;
    }
    return sol;
}
