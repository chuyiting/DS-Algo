//
// Created by Eddy Chu on 2023/8/8.
//

#include "TopKFrequent.h"
#include <unordered_map>
#include <algorithm>
#include <vector>

/**
 * Sort O(nlogn)
 */

bool sortBySecDesc (const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return p1.second > p2.second;
}

std::vector<int> TopKFrequent::topKFrequent1(std::vector<int> &nums, int k) {
    std::vector<int> ans;
    std::unordered_map<int, int> counts;
    for (const auto &num : nums) {
        counts[num]++;
    }

    std::vector<std::pair<int, int>> counts_vec;
    for (const auto &p : counts) {
        counts_vec.emplace_back(p);
    }

    std::sort(counts_vec.begin(), counts_vec.end(), sortBySecDesc);
    for (int i = 0; i < k; i++) {
        ans.push_back(counts_vec[i].first);
    }

    return ans;
}

/**
 * Max Heap O(klogn)
 */
std::vector<int> TopKFrequent::topKFrequent2(std::vector<int> &nums, int k) {
    return std::vector<int>();
}

/**
 * O(n)
 */
std::vector<int> TopKFrequent::topKFrequent3(std::vector<int> &nums, int k) {
    return std::vector<int>();
}
