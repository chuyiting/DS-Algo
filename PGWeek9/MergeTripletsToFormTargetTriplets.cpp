//
//  MergeTripletsToFormTargetTriplets.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/31.
//

#include "MergeTripletsToFormTargetTriplets.hpp"

bool MergeTripletsToFormTargetTriplets::mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
    unsigned int sol = 0b000;
    
    for (auto &triplet : triplets) {
        unsigned int tmp = 0b000;
        bool canUse = true;
        for (int i = 0; i < triplet.size(); i++) {
            if (triplet[i] > target[i]) {
                canUse = false;
                break;
            } else if (triplet[i] == target[i]){
                tmp = tmp | 1 << i;
            }
        
        }
        if (canUse) {
            sol = sol | tmp;
        }
    }
    return (sol & 0b111) == 0b111;
    
}
