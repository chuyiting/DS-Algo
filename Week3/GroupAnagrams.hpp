//
//  GroupAnagrams.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/15.
//

#ifndef GroupAnagrams_hpp
#define GroupAnagrams_hpp

#include <stdio.h>
#include <string>
#include <vector>

class GroupAnagrams {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
    
    
    std::string getSignature(const std::string& word);
    
    std::vector<std::vector<std::string>> groupAnagrams2(std::vector<std::string>& strs);
};

#endif /* GroupAnagrams_hpp */
