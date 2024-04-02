//
//  EvaluateReversePolishNotation.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/2.
//

#include "EvaluateReversePolishNotation.hpp"
#include <stack>
#include <ctype.h>
#include <string.h>

int EvaluateReversePolishNotation::evalRPN(std::vector<std::string>& tokens) {
    
    std::stack<int> operands;
    for (const auto& token : tokens) {
        try {
            operands.push(std::stoi(token));
            continue;
        } catch (std::invalid_argument const& ex) {
            int rhs = operands.top();
            operands.pop();
            int lhs = operands.top();
            operands.pop();
            
            switch (token[0]) {
                case '+':
                    operands.push(lhs + rhs);
                    break;
                case '-':
                    operands.push(lhs - rhs);
                    break;
                case '*':
                    operands.push(lhs * rhs);
                    break;
                case '/':
                    operands.push(lhs / rhs);
                    break;
            }
        }
        
    }
    return operands.top();
    
}
