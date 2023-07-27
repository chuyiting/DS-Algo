//
// Created by Eddy Chu on 2023/7/27.
//

#include "ValidAnagram.h"
#include <unordered_map>

bool ValidAnagram::isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, int> dict;
    for (const auto& c:s) {
        if (dict.find(c) != dict.end()) {
            dict[c]++;
        } else {
            dict[c] = 1;
        }
    }

    for (const auto& c:t) {
        if (dict.find(c) == dict.end()) return false;
        dict[c]--;
        if (dict[c] < 0) return false;
    }

    return true;

}