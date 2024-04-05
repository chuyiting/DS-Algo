//
//  SearchA2DMatrix.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/5.
//

#include "SearchA2DMatrix.hpp"

bool SearchA2DMatrix::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m*n-1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        int i = mid / n, j = mid % n;
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
    
}
