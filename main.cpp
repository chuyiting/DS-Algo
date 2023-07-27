#include <iostream>
#include "Week1/TwoSum.h"
#include "Week1/ValidAnagram.h"
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

int main() {
//    testTwoSum();
    testValidAnagram();
    return 0;
}
