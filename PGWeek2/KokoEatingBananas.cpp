//
//  KokoEatingBananas.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/5.
//

#include "KokoEatingBananas.hpp"

int KokoEatingBananas::minEatingSpeed(std::vector<int>& piles, int h) {
    int l = 1, r = 0;
    for (const auto& pile : piles) {
        r = std::max(r, pile);
    }
    
    int sol = r;
    while (l <= r) {
        int mid = (l+r) / 2;
        int hourTofinish = 0;
        for (const auto& pile : piles) {
            if (pile % mid ==  0)  {
                hourTofinish += pile / mid;
            } else {
                hourTofinish += pile / mid + 1;
            }
            
            if (hourTofinish > h) {
                break;
            }
        }
        
        if (hourTofinish <= h) {
            sol = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return sol;
}
