//
//  AncestralName.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/21.
//

#include "AncestralName.hpp"
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <iostream>


struct SortByName {
    bool operator()(std::vector<std::string> &n1, std::vector<std::string> &n2) {
        return n1[0] < n2[0];
    }
};

struct SortByNum {
    std::unordered_map<char, int> mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}};
    int romanToInt(std::string roman) {
        int result = 0;
        for (int i = 0; i < roman.size(); i++) {
            if (i < roman.size()-1 && mapping[roman[i]] < mapping[roman[i+1]]) {
                result -= mapping[roman[i]];
            } else {
                result += mapping[roman[i]];
            }
        }
        return  result;
    }
    bool operator()(std::vector<std::string> &n1, std::vector<std::string> &n2) {
        return romanToInt(n1[1]) < romanToInt(n2[1]);
    }
};

void AncestralName::sortNames(std::vector<std::string> names) {
    std::vector<std::vector<std::string>> parsedNames;
    for (const auto &name : names) {
        std::stringstream ss(name);
        std::string token;
        std::vector<std::string> parsed;
        while (std::getline(ss, token, ' ')) {
            parsed.push_back(token);
        }
        parsedNames.push_back(parsed);
    }
    
    std::sort(parsedNames.begin(), parsedNames.end(), SortByNum());
    std::sort(parsedNames.begin(), parsedNames.end(), SortByNum());
}
