//
//  AddTwoNumbers.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/9.
//

#ifndef AddTwoNumbers_hpp
#define AddTwoNumbers_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
}

#endif /* AddTwoNumbers_hpp */
