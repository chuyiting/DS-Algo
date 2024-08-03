//
//  ValidParenthesisString.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#include "ValidParenthesisString.hpp"
#include <queue>
#include <stack>

bool ValidParenthesisString::checkValidString(std::string s) {
    std::stack<int> star;
    std::stack<int> left;
    
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            left.push(i);
        } else if (c =='*') {
            star.push(i);
        } else {
            if (left.empty() && star.empty()) {
                return false;
            } else if (!left.empty()) {
                left.pop();
            } else {
                star.pop();
            }
        }
    }
    while (!star.empty()) {
        if (left.empty()) break;
        if (star.top() < left.top()) {
            star.pop();
        } else {
            left.pop();
            star.pop();
        }
    }
    
    return left.empty();
}

bool ValidParenthesisString::checkValidString2(std::string s) {
    int leftMax = 0;
    int leftMin = 0;
    
    for (auto &c : s) {
        if (c == '(') {
            leftMax++;
            leftMin++;
        } else if (c == '*') {
            leftMax++;
            leftMin = std::max(leftMin-1, 0);
        } else {
            if (leftMax <= 0) return false;
            leftMax--;
            leftMin = std::max(leftMin-1, 0);
        }
    }
    return leftMin == 0;
}
