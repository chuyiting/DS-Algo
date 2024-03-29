//
// Created by Eddy Chu on 2023/8/8.
//

#include "TopKFrequent.h"
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>

typedef std::pair<int, int> intp;

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

struct intPairComparator {
    const bool operator()(std::pair<int, int> const& a,
                          std::pair<int, int> const& b) const noexcept {
        return a.second < b.second;
    }
};
/**
 * Max Heap O(klogn)
 */
std::vector<int> TopKFrequent::topKFrequent2(std::vector<int> &nums, int k) {
    std::vector<int> ans;
    std::unordered_map<int, int> counts;
    for (const auto &num: nums) {
        counts[num]++;
    }
    
    std::priority_queue<intp, std::vector<intp>, intPairComparator> pq;
    for (const auto& p: counts) {
        pq.push(p);
    }
    
    for (int i = 0; i < k; ++i) {
        ans.emplace_back(pq.top().first);
        pq.pop();
    }
    return ans;
}

/**
 * O(n)
 */
std::vector<int> TopKFrequent::topKFrequent3(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::unordered_map<int, int> count;
    std::vector<std::vector<int>> countBucket(n+1);
    for (const auto& num: nums) {
        count[num]++;
    }
    
    for (const auto& countp : count) {
        countBucket[countp.second].push_back(countp.first);
    }
    
    std::vector<int> ans;
    
    for (int i = n; i > 0; i--) {
        for (const auto& val: countBucket[i]) {
            if (ans.size() == k) {
                break;
            }
            
            ans.push_back(val);
        }
        
        if (ans.size() == k) {
            break;
        }
    }
    
    return ans;
}
