//
//  LongestIncreasingSubsequence.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/16.
//

#include "LongestIncreasingSubsequence.hpp"
#include <algorithm>

// O(n^2) dynamic programming <ii> find LCS for sorted nums and nums!!
int LongestIncreasingSubsequence::lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> lengths(nums.size(), 1);
    lengths[0] = 1;
    int sol = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i-1; j >= 0;j--) {
            if (nums[i] > nums[j]) {
                lengths[i] = std::max(lengths[i], lengths[j] + 1);
            }
        }
        sol = std::max(lengths[i], sol);
    }
    return sol;
}

// O(n log n) Patience Solitaire dealing card!!
int LongestIncreasingSubsequence::lengthOfLISPS(std::vector<int>& nums) {
    std::vector<int> deckOfCards;
    deckOfCards.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > deckOfCards[deckOfCards.size()-1]) {
            deckOfCards.push_back(nums[i]);
        } else {
            int l = 0, r = deckOfCards.size()-1;
            while (l <= r) {
                int mid = (l+r) / 2;
                if (deckOfCards[mid] >= nums[i] && (mid == 0 || deckOfCards[mid-1] < nums[i])) {
                    deckOfCards[mid] = nums[i];
                    break;
                } else if (deckOfCards[mid] > nums[i]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
    }
    return deckOfCards.size();
}
