//
//  CopyListWithRandomPointer.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/8.
//

#ifndef CopyListWithRandomPointer_hpp
#define CopyListWithRandomPointer_hpp

#include <stdio.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class CopyListWithRandomPointer {
public:
    Node* copyRandomList(Node* head);
};

#endif /* CopyListWithRandomPointer_hpp */
