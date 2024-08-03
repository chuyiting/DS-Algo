//
//  RegularExpressionMatching.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/24.
//

#include "RegularExpressionMatching.hpp"
#include <vector>

bool isCharMatch(char c, char p){
    if (p ==  '.') return true;
    return c == p;
}

bool RegularExpressionMatching::isMatch(std::string s, std::string p) {
    std::vector<std::vector<bool>> match(s.size()+1, std::vector<bool>(p.size()+1, false));
    
    match[0][0] = true;
    int pi = 0;
    while (pi+1 < p.size() && p[pi+1]  == '*') {
        for (int i = 0; i < match.size(); i++) {
            match[i][pi+1] = true;
            match[i][pi+2] = true;
        }
        pi += 2;
    }
    
    for (int i = 1; i < match.size(); i++) {
        int j = 1;
        while (j < match[0].size()) {
            if (j < p.size() && p[j]== '*'){
                int k = 0;
                match[i][j] = match[i][j-1];
                while (!match[i][j] && isCharMatch(s[i-k-1], p[j-1])) {
                    match[i][j] = match[i][j] || match[i-k-1][j];
                    k++;
                }
                match[i][j+1] = match[i][j];
                j += 2;
            } else if (isCharMatch(s[i-1], p[j-1])){
                match[i][j] = match[i-1][j-1];
                j++;
            } else {
                match[i][j] = false;
                j++;
            }
            
        }
    }
    
    return match[s.size()][p.size()];
}
