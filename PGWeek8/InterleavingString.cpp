//
//  InterleavingString.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/19.
//

#include "InterleavingString.hpp"
#include <vector>

bool InterleavingString::isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s2.size() < s1.size()) {
        std::string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    
    if (s3.size() != s1.size() + s2.size()) return false;
    
    std::vector<bool> curr(s1.size()+1, false);
    std::vector<bool> prev(s1.size()+1, false);
    prev[0] = true;
    for (int i = 1; i < prev.size(); i++) {
        prev[i] = prev[i-1] && s3[i-1] == s1[i-1];
    }
    
    for (int i = 0; i < s2.size(); i++) {
        curr[0] = prev[0] && s3[i] == s2[i];
        for (int j = 1; j < curr.size(); j++) {
            if (s3[i+j] == s1[j-1]) {
                curr[j] = curr[j] || curr[j-1];
            }
            if (s3[i+j] == s2[i]) {
                curr[j] = curr[j] || prev[j];
            }
            
        }
        prev = curr;
    }
    
    return curr[curr.size()-1];
}
