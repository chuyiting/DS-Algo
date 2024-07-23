//
//  StringEncodeAndDecode.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/11.
//

#include "StringEncodeAndDecode.hpp"
#include <sstream>


std::string StringEncodeAndDecode::encode(std::vector<std::string>& strs) {
    std::string sol;
    for (const auto &str : strs) {
        sol += std::to_string(str.size());
        sol += '#';
        sol += str;
    }
    return sol;
}

std::string readNChar(std::stringstream& ss, int n) {
    std::string sol = "";
    char c;
    for (int i = 0; i < n && ss.get(c); i++) {
        sol += c;
    }
    return sol;
}

std::vector<std::string> StringEncodeAndDecode::decode(std::string s) {
    std::vector<std::string> sol;
    
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, '#')) {
        int n = std::stoi(token);
        sol.push_back(readNChar(ss, n));
    }
    return sol;
    
}


