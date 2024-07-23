//
//  StringEncodeAndDecode.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/11.
//

#ifndef StringEncodeAndDecode_hpp
#define StringEncodeAndDecode_hpp

#include <stdio.h>
#include <string>
#include <vector>

class StringEncodeAndDecode {
public:
    std::string encode(std::vector<std::string>& strs);

    std::vector<std::string> decode(std::string s);
};

#endif /* StringEncodeAndDecode_hpp */
