//
//  MinStack.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/2.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>
#include <stack>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;
public:
    MinStack() {
        
    }
    void push(int val) {
        this->stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    void pop() {
        if (this->minStack.top() == this->stack.top()) {
            this->minStack.pop();
        }
        this->stack.pop();
    }
    int top() {
        return this->stack.top();
    }
    int getMin() {
        return this->minStack.top();
    }
};

#endif /* MinStack_hpp */
