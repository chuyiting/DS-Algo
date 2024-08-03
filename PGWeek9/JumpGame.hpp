//
//  JumpGame.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/7/27.
//

#ifndef JumpGame_hpp
#define JumpGame_hpp

#include <stdio.h>
#include <vector>

class JumpGame {
public:
    bool canJump(std::vector<int>& nums);
    bool canJumpGreedy(std::vector<int>& nums);
};

#endif /* JumpGame_hpp */
