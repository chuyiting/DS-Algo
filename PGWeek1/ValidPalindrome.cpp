//
//  ValidPalindrome.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/3/30.
//

#include "ValidPalindrome.hpp"
#include <algorithm>
#include <ctype.h>
#include <cstring>

bool ValidPalindrome::isPalindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](auto c){return !isalnum(c);}), s.end());
    
    auto l = s.begin();
    auto r = s.end()-1;
    
    while (r > l) {
        if (std::tolower(*r) != std::tolower(*l)) {
            return false;
        }
        r--;
        l++;
    }
    return true;
}
