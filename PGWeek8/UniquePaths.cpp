//
//  UniquePaths.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/17.
//

#include "UniquePaths.hpp"
#include <vector>

int UniquePaths::uniquePaths(int m, int n) {
    std::vector<std::vector<int>> numOfPaths(m, std::vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            numOfPaths[i][j] = numOfPaths[i-1][j] + numOfPaths[i][j-1];
        }
    }
    return numOfPaths[m-1][n-1];
}

int UniquePaths::uniquePaths2(int m, int n) {
    int s = std::min(m, n);
    int l = std::max(m, n);
    std::vector<int> curr(s, 1);
    std::vector<int> prev(s, 1);
    
    for (int i = 1; i < l; i++) {
        for (int j = 1; j < s; j++) {
            curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }
    return curr[s-1];
}

int UniquePaths::uniquePaths3(int m, int n) {
    int s = std::min(m, n);
    int l = std::max(m, n);
    std::vector<int> curr(s, 1);
    std::vector<int> prev(s, 1);
    
    for (int i = 1; i < l; i++) {
        for (int j = 1; j < s; j++) {
            curr[j] = prev[j] + curr[j-1];
        }
        prev = curr;
    }
    return curr[s-1];
}
