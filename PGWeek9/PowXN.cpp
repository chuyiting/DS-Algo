//
//  PowXN.cpp
//  ds_algo
//
//  Created by Eddy Chu on 2024/8/2.
//

#include "PowXN.hpp"
#include <climits>
#include <cmath>

double PowXN::myPow(double x, int n) {
    if (n == 0) return 1;

    double pow = x;
    bool isNeg = n < 0;
    bool minInt = false;
    if (isNeg && n > INT_MIN) {
        n = -n;
    } else if (isNeg) {
        n = -(n+1);
        minInt = true;
    }
    double currPow = 1;
    
    while (currPow * 2 < n) {
        pow *= pow;
        currPow *= 2;
    }
    for (int i = currPow; i < n; i++) {
        pow *= x;
    }

    if (minInt) {
        pow = 1.0/(pow * x);
    } else if (isNeg) {
        pow = 1.0 / pow;
    }
    return pow;
}


double PowXN::myPowRecursive(double x, int n) {
    double sol = myPow(x, abs(n));
    return n < 0 ? 1.0 / sol : sol;
}

double PowXN::myPowRecursiveHelper(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    double res = myPowRecursiveHelper(x, n/2);
    if (n%2 == 0) {
        return res * res;
    } else {
        return x * res * res;
    }
}
