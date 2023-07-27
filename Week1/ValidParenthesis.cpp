//
// Created by Eddy Chu on 2023/7/27.
//

#include "ValidParenthesis.h"
#include<stack>
#include<unordered_map>

bool ValidParenthesis::isValid(std::string s) {
    std::stack<char> visited;
    std::unordered_map<char, char> lefts = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
    };

    for (const auto&c:s) {
        if (lefts.find(c) != lefts.end()) {
            visited.push(c);
            continue;
        }

        if (visited.empty()) return false;
        auto curr = visited.top();
        if (lefts[curr] != c) return false;
        visited.pop();
    }

    return visited.empty();
}