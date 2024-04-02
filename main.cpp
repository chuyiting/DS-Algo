#include <iostream>
#include "Week1/TwoSum.h"
#include "Week1/ValidAnagram.h"
#include "Week1/ValidParenthesis.h"
#include "Week1/IOPractice.h"
#include "Week2/TopKFrequent.h"
#include "Week3/FindTheDuplicateNumber.hpp"
#include "Week3/SubarraySumEqualsK.hpp"
#include "Week3/ContinuousSubarraySum.hpp"
#include "Week3/MergeIntervals.hpp"
#include "Week3/ProductOfArrayExceptSelf.hpp"
#include "Week3/MaximumProductSubarray.hpp"
#include "Week3/SearchInRotatedSortedArray.hpp"
#include "PGWeek1/LongestSubstringWithoutRepeatingChar.hpp"
#include "PGWeek2/EvaluateReversePolishNotation.hpp"
#include <vector>
#include <string>

template<typename Container>
void print(const Container &container) {
    for (const auto &item: container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


void testTwoSum() {
    auto twoSum = std::make_shared<TwoSum>();

    std::vector<int> input1 = {1, 2, 3, 4, 5, 6};
    int target1 = 8;
    print(twoSum->twoSum(input1, target1));
}

void testValidAnagram() {
    auto validAnagram = std::make_shared<ValidAnagram>();

    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::cout << validAnagram->isAnagram(s1, t1) << "\n";

    std::string s2 = "car";
    std::string t2 = "rat";
    std::cout << validAnagram->isAnagram(s2, t2) << "\n";

}

void testValidParenthesis() {
    auto validParenthesis = std::make_shared<ValidParenthesis>();
    std::string s1 = "([{}])";
    std::string s2 = "([)]";
    std::cout << validParenthesis->isValid(s1) << '\n';
    std::cout << validParenthesis->isValid(s2) << '\n';

}

void testIOPractice() {
    auto ioPractice = std::make_shared<IOPractice>();
    ioPractice->outputPractice();
}

void testTopKFrequent() {
    auto topKFrequent = std::make_shared<TopKFrequent>();
    std::vector<int> input1 = {1};
    int k1 = 1;
    print(topKFrequent->topKFrequent3(input1, k1));
}

void testFindTheDuplicateNumber() {
    auto findTheDuplicateNmber = std::make_shared<FindTheDuplicateNumber>();
    std::vector<int> input = {1, 3, 4, 2, 2};
    std::cout << findTheDuplicateNmber -> findDuplicate(input) << std::endl;
}

void testSubarraySum() {
    auto subarraySumEqualsK = std::make_shared<SubarraySumEqualsK>();
    std::vector<int> input1 = {1, 1, 1};
    int k1 = 2;
    std::cout << subarraySumEqualsK -> subarraySum(input1, k1) << std::endl;
    std::cout << subarraySumEqualsK -> subarraySum2(input1, k1) << std::endl;
    
    
    std::vector<int> input2 = {1, 2, 3};
    int k2 = 3;
    std::cout << subarraySumEqualsK -> subarraySum(input2, k2) << std::endl;
    std::cout << subarraySumEqualsK -> subarraySum2(input2, k2) << std::endl;
}

void testContinuousSubarraySum() {
    auto continuousSubarraySum = std::make_shared<ContinuousSubarraySum>();
    std::vector<int> input1 = {23, 2, 4, 6, 7};
    int k1 = 29;
    std::cout << continuousSubarraySum -> checkSubarraySum(input1, k1) << std::endl;
}

void testMergeIntervals() {
    auto mergeIntervalsObj = std::make_shared<MergeIntervals>();
    std::vector<std::vector<int>> input1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto result = mergeIntervalsObj -> merge(input1);
    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        std::cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i != result.size()-1) std::cout << ", ";
    }
    
    std::cout << "]" << std::endl;
}

void testProductExceptSelf() {
    auto productExceptSelfSol = std::make_shared<ProductOfArrayExceptSelf>();
    std::vector<int> input = {1, 2, 3, 4};
    print(productExceptSelfSol->productExceptSelf(input));
}

void testMaximumProductSubarray() {
    auto maxProductSub = std::make_shared<MaximumProductSubarray>();
    std::vector<int> input = {-2, -3, -4};
    std::cout << maxProductSub->maxProduct(input) << std::endl;
}

void testSearchInRotatedSortedArray() {
    auto searchInRotatedSortedArray = std::make_shared<SearchInRotatedSortedArray>();
    std::vector<int> input = {4,5,6,7,0,1,2};
    int target = 0;
    std::cout << searchInRotatedSortedArray -> search(input, target) << std::endl;
    std::cout << searchInRotatedSortedArray -> search(input, 9) << std::endl;
    
}

void testlongestSubstringWithoutRepeatingChar() {
    auto longestSubstringWithoutRepeatingChar = std::make_shared<LongestSubstringWithoutRepeatingChar>();
    std::string input = "abcabcbb";
    std::cout << longestSubstringWithoutRepeatingChar -> lengthOfLongestSubstring(input) << std::endl;
}

void testEvaluateReversePolishNotation() {
    auto evaluateReversePolishNotation = std::make_shared<EvaluateReversePolishNotation>();
    std::vector<std::string> input {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << evaluateReversePolishNotation->evalRPN(input) << std::endl;
}

int main() {
//    testTwoSum();
//    testValidAnagram();
//    testValidParenthesis();
//    testProductExceptSelf();
//    testMaximumProductSubarray();
//    testSearchInRotatedSortedArray();
//    testlongestSubstringWithoutRepeatingChar();
    testEvaluateReversePolishNotation();
    return 0;
}
