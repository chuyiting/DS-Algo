//
//  BrazeOA.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/10/7.
//

#include "BrazeOA.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>

class Discount {
public:
    virtual int getDiscountedPrice(float price) const = 0;
};

class Type0Discount : public Discount {
    int discountedPrice;
public:
    Type0Discount(int discountedPrice) {
        this->discountedPrice = discountedPrice;
    }
    
    int getDiscountedPrice(float price) const override {
        return discountedPrice;
    }
};

class Type1Discount : public Discount {
    int percentage;
public:
    Type1Discount(int percentage) {
        this->percentage = percentage;
    }
    
    int getDiscountedPrice(float price) const override {
        return int(price * percentage / 100.0);
    }
};

class Type2Discount : public Discount {
    int amount;
public:
    Type2Discount(int amount) {
        this->amount = amount;
    }
    
    int getDiscountedPrice(float price) const override {
        return price - this->amount;
    }
};

void validateDiscountVector(std::vector<std::string> &discount) {
    if (discount.size() != 3) {
        throw std::invalid_argument("expect discount vector to be of size 3, but get " + std::to_string(discount.size()));
    }
};

class DiscountFactory {
public:
    Discount *createDiscount(std::vector<std::string> discount) {
        validateDiscountVector(discount);
    }
};

class DiscountStorage {
    
};
