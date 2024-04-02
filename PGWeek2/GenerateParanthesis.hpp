//
//  GenerateParanthesis.hpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/4/2.
//

#ifndef GenerateParanthesis_hpp
#define GenerateParanthesis_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <numeric>

class GenerateParanthesis {
private:
    std::vector<std::string> paranStack;
    std::vector<std::string> sol;
    
    std::vector<std::string> generate(std::string prefix, int lLeft, int rLeft) {
        if (lLeft == 0 && rLeft  == 0)  {
            return {prefix};
        }
        
        if (lLeft == 0) {
            for (int i = 0; i < rLeft; i++) {
                prefix += ")";
            }
            return {prefix};
        }
        
        if (lLeft == rLeft){
            return generate(prefix + "(", lLeft-1, rLeft);
        }
        
        auto result1 = generate(prefix + "(", lLeft-1, rLeft);
        auto result2 = generate(prefix + ")", lLeft, rLeft-1);
        result1.insert(result1.end(), result2.begin(), result2.end());
        return result1;
    }
    
    void generate2(int lLeft, int rLeft) {
        if (lLeft == 0 && rLeft == 0) {
            auto s = std::accumulate(this->paranStack.begin(), this->paranStack.end(), std::string());
            sol.push_back(s);
        }
        
        if (lLeft > 0) {
            this->paranStack.push_back("(");
            this->generate2(lLeft-1, rLeft);
            this->paranStack.erase(paranStack.end()-1);
        }
        
        if (rLeft > lLeft) {
            this->paranStack.push_back(")");
            this->generate2(lLeft, rLeft-1);
            this->paranStack.erase(paranStack.end()-1);
        }
    }
    
public:
    std::vector<std::string> generateParenthesis(int n) {
        return this->generate("", n, n);
    }
    
    std::vector<std::string> generateParenthesis2(int n) {
        this->generate2(n, n);
        return sol;
    }
    
    
};

#endif /* GenerateParanthesis_hpp */
