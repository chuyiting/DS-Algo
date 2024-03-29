//
//  ThreeSum.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/2/15.
//

#include "ThreeSum.hpp"
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

std::vector<std::vector<int>> ThreeSum::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int j = i+1, k = nums.size()-1;
        
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                std::vector<int> three = {nums[i], nums[j], nums[k]};
                ans.push_back(three);
            }
            
            if (sum > 0) {
                int prevK = k;
                while (k > j && nums[k] == nums[prevK]) k--;
            } else {
                int prevJ = j;
                while (j < nums.size() && nums[j] == nums[prevJ]) j++;
            }
        }
    }
    
    return ans;
    
}
