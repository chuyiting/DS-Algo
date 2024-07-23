//
//  LongestIncreasingPathInMatrix.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/19.
//

#include "LongestIncreasingPathInMatrix.hpp"
#include <utility>
#include <algorithm>
#include <queue>

int findMaxNeighbor (std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& longestPath, int i, int j) {
    std::vector<std::vector<int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxNeighbor = 0;
    int curr = matrix[i][j];
    int m = matrix.size();
    int n = matrix[0].size();
    for (auto &neighbor : neighbors) {
        int nxti = i + neighbor[0];
        int nxtj = j + neighbor[1];
        if  (nxti >= 0 && nxti < m && nxtj >= 0 && nxtj < n && matrix[nxti][nxtj] > curr && longestPath[nxti][nxtj] == 0) {
            return 0;
        } else if (nxti >= 0 && nxti < m && nxtj >= 0 && nxtj < n && matrix[nxti][nxtj] > curr) {
            maxNeighbor = std::max(maxNeighbor, longestPath[nxti][nxtj]);
        }
    }
    return maxNeighbor;
}

std::vector<std::pair<int, int>> findMax(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& longestPath) {
    int maxVal = -1;
    std::vector<std::pair<int, int>> maxes;
    for (int i = 0; i < longestPath.size(); i++) {
        for (int j = 0; j < longestPath[0].size(); j++) {
            if (longestPath[i][j] == 0 && matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxes = {{i, j}};
            } else if (longestPath[i][j] == 0 && matrix[i][j] == maxVal) {
                maxes.push_back({i, j});
            }
        }
    }
    return maxes;
}
 
int LongestIncreaingPathInMatrix::longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> longestPath(m, std::vector<int>(n, 0));
    
    std::queue<std::pair<int, int>> q;
    
    int sol = 1;
    int resolve = 0;
    std::vector<std::vector<int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (resolve != m*n) {
        if (q.empty()) {
            auto nxtLst = findMax(matrix, longestPath);
            for (auto &maxPos : nxtLst) {
                longestPath[maxPos.first][maxPos.second] = 1;
            }
            resolve += nxtLst.size();
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (auto &neighbor : neighbors) {
                int nxtr = r + neighbor[0];
                int nxtc = c + neighbor[1];
                if  (nxtr >= 0 && nxtr < m && nxtc >= 0 && nxtc < n && longestPath[nxtr][nxtc] == 0) {
                    int maxNei = findMaxNeighbor(matrix, longestPath, nxtr, nxtc);
                    if (maxNei != 0) {
                        longestPath[nxtr][nxtc] = maxNei + 1;
                        resolve++;
                        sol = std::max(sol, longestPath[nxtr][nxtc]);
                        q.push({nxtr, nxtc});
                    }
                }
            }
        }
        
    }
    return sol;
}
