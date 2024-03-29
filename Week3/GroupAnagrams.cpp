//
//  GroupAnagrams.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/15.
//

#include "GroupAnagrams.hpp"
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> GroupAnagrams::groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, int> anagramIdx;
    std::vector<std::vector<std::string>> ans;
    for (const auto &str : strs) {
        std::string strCpy = str;
        sort(strCpy.begin(), strCpy.end());
        if (anagramIdx.find(strCpy) != anagramIdx.end()) {
            ans[anagramIdx[strCpy]].push_back(str);
        } else {
            anagramIdx[strCpy] = ans.size();
            ans.push_back({str});
        }
    }
    
    return ans;
    
}

std::string GroupAnagrams::getSignature(const std::string& word) {
    std::vector<int> count(26, 0);
    for (const char& c : word) {
        count[c - 'a']++;
    }
    
    std::string signature = "";
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            signature += ('a' + i);
            signature += std::to_string(count[i]);
        }
    }
    return signature;
}

std::vector<std::vector<std::string>> GroupAnagrams::groupAnagrams2(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> ans;
    std::unordered_map<std::string, int> groupIds;
    
    for (const auto&str : strs) {
        std::string signature = getSignature(str);
        if (groupIds.find(signature) == groupIds.end()) {
            groupIds[signature] = ans.size();
            ans.push_back({str});
        } else {
            ans[groupIds[signature]].push_back(str);
        }
    }
    
    return ans;
}
