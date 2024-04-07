//
//  MediumOfTwoSortedArray.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/7.
//

#include "MediumOfTwoSortedArray.hpp"
#include <vector>
#include <cmath>

double MediumOfTwoSortedArray::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        std::vector<int> temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
    
    if (nums1.size() == 0) {
        return nums2.size() % 2 == 0 ? (nums2[nums2.size()/2] + nums2[nums2.size()/2-1]) / 2.0 : nums2[nums2.size()/2];
    }

    int l = -1, r = nums1.size()-1;
    int half = std::ceil((nums1.size() + nums2.size()) / 2.0);
    while (l <= r) {
        int nums1Id = (l + r) / 2;
        int nums2Id = half - nums1Id - 2;
        
        int nums1left = nums1Id >= 0 ? nums1[nums1Id] : INT_MIN;
        int nums1right = nums1Id == nums1.size()-1 ? INT_MAX : nums1[nums1Id + 1];
        int nums2left = nums2Id >= 0 ? nums2[nums2Id] : INT_MIN;
        int nums2right = nums2Id == nums2.size()-1 ? INT_MAX: nums2[nums2Id + 1];
        
        if (nums1left <= nums2right && nums2left <= nums1right) {
            if ((nums1.size() + nums2.size()) % 2 == 0) {
                return (std::max(nums1left, nums2left) + std::min(nums1right, nums2right)) / 2.0;
            } else {
                return std::max(nums1left, nums2left);
            }
        } else if (nums1left > nums2right) {
            r = nums1Id-1;
        } else {
            l = nums1Id+1;
        }
    }
    return -1.0;
    
}
