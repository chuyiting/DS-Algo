//
//  DecodeWays.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/15.
//

#include "DecodeWays.hpp"

int DecodeWays::numDecodings(std::string s) {
    if (s[0] == '0') return 0;
    int prev = 1, curr = 1;

    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        int ways = 0;

        if (s[i] != '0') {
            ways += curr;
        }

        if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
            ways += prev;
        }
        
        curr = ways;
        prev = tmp;
    }
    return curr;
}
