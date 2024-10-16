//
//  CirculaPrinter.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/9/21.
//

#include "CirculaPrinter.hpp"
#include <algorithm>
#include <cmath>


int CircularPrinter::getTime(std::string str) {
    int sol = 0;
    char prev = 'a';
    for (const auto&c : str) {
        int turn = std::abs(c - prev);
        sol += std::min(turn, 26-turn);
    }
    return sol;
}
