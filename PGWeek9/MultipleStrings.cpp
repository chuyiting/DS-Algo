//
//  MultipleStrings.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "MultipleStrings.hpp"
#include <vector>


std::string add(std::string num1, std::string num2, int carry) {
    if (num1.size() == 0 && num2.size() == 0) {
        if (carry == 0) return "";
        return std::to_string(carry);
    }
    
    if (num1.size() == 0) {
        if (carry == 0) return num2;
        int sum = (num2[num2.size()-1] - '0') + carry;
        return add(num1, num2.substr(0, num2.size()-1), sum/10) + std::to_string(sum%10);
    }
    
    if (num2.size() == 0) {
        if (carry == 0) return num1;
        int sum = (num1[num1.size()-1] - '0') + carry;
        return add(num1.substr(0, num1.size()-1), num2, sum/10) + std::to_string(sum%10);
    }
  
    int sum = (num1[num1.size()-1] - '0') + (num2[num2.size()-1] - '0') + carry;
    return add(num1.substr(0, num1.size()-1), num2.substr(0, num2.size()-1), sum/10) + std::to_string(sum%10);
}

std::string singleDigitMultiply(std::string num, int digit) {
    int carry = 0;
    std::string sol = "";
    for (int i = num.size()-1; i >= 0; i--) {
        int curr = (num[i]-'0') * digit + carry;
        carry = curr / 10;
        sol = std::to_string(curr % 10) + sol;
    }
    if (carry != 0) {
        sol = std::to_string(carry) + sol;
    }
    return sol;
}

std::string MultipleStrings::multiply(std::string num1, std::string num2) {
    if (num1.size() > num2.size()) {
        std::string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    if (num1 == "0") return "0";
    
    std::string sol = "";
    std::string pad = "";
    for (int i = 0; i < num1.size(); i--) {
        sol = add(sol, singleDigitMultiply(num2, num1[i]-'0')+pad, 0);
        pad += '0';
    }
    return sol;
}

std::string MultipleStrings::multiply2(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    std::vector<int> sol(num1.size()+num2.size(), 0);
    
    for (int i = num1.size()-1; i >= 0; i--) {
        for (int j = num2.size()-1; j >=  0; j--) {
            int id = num1.size()-1-i + num2.size()-1-j;
            int product = (num1[i] - '0') * (num2[j] - '0') + sol[id];
            sol[id] = product % 10;
            sol[id+1] += product / 10;
        }
    }
    
    std::string solstr = "";
    int endIdx = sol.size()-1;
    for (int i = sol.size()-1; i >= 0; i--) {
        if (sol[i] != 0) {
            endIdx  =  i;
            break;
        }
    }
    
    for(int i = 0; i <= endIdx; i++) {
        solstr = std::to_string(sol[i]) + solstr;
    }
    return solstr;
}
