#include <iostream>
#include "Week1/TwoSum.h"
#include "Week1/ValidAnagram.h"
#include "Week1/ValidParenthesis.h"
#include "Week1/IOPractice.h"
#include "Week2/TopKFrequent.h"
#include <vector>
#include <string>

template<typename Container>
void print(const Container &container) {
    for (const auto &item: container) {
        std::cout << item << " ";
    }
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
    std::vector<int> input1 = {1, 1, 1, 1, 2, 2, 2, 3};
    int k1 = 2;
    print(topKFrequent->topKFrequent1(input1, k1));
}

int main() {
//    testTwoSum();
//    testValidAnagram();
//    testValidParenthesis();
    testTopKFrequent();
    return 0;
}
