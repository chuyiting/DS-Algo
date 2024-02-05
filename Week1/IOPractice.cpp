//
// Created by Eddy Chu on 2023/7/28.
//

#include "IOPractice.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>

void IOPractice::outputPractice() {
    int age = 25;
    printf("My age is %d\n", age); // Not type-safe; Runtime error for mismatch

    // Manipulators: objects that cause output stream object to do smth to its output or its member variable
    // Manipulator without arguments #include<iostream> e.g. endl
    // Manipulator with argument #include<iomanip> e.g. setprecision(), setw()

    // Manipulator 1: endl
    // An object when supplied to operator<<, cause a newline character to put into the output stream
    // Followed by a call of cout's flush function (empty internal buffer)
    std::cout << "Hello World!" << std::endl;


    // Operator <<
    // Has overloaded function for all of the built-in type

    // Stream setting
    // stored in the ios object included in <iostream>
    std::ios::fmtflags old_setting = std::cout.flags();

    // restore flags
    std::cout.flags(old_setting);

    /*
     * set precision for all the outputs
     * cout << setprecision(4) << 1234.5678 << 12345.0;
     * 1234 1.234e+04
     */
    int old_precision = std::cout.precision();
    // restore precision
    std::cout.precision(old_precision);
    // reset precision
    std::cout.precision(0);


    /*
     * set width of the immediate following output
     * blank will be added
     * if not fit, the extra digits will still be printed regardless of the field width
     */
    std::cout << std::setw(4) << 12 << std::endl;

    /*
     * fixed floating point format
     * prevent flipping into scientific notation
     * set specified number of places to the right of the decimal point
     */
    // <i> 2 digits to the right
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    // <ii>
    std::cout << std::fixed << std::setprecision(2);
    // reset the floating-point format flags
    std::cout.setf(0, std::ios::floatfield);


    /*
     * Default formatting: 6 significant digits (left + right) or fewer
     */
    int nvalues = 20;
    int ipow[nvalues];
    double ary[nvalues];
    IOPractice::setPrintValues(ipow, ary, nvalues);

    std::cout << std::fixed << std::setprecision(8);
    for (int i = 0; i < nvalues; i++) {
        std::cout << std::setw(3) << ipow[i] << ' ' << std::setw(18) << ary[i] << std::endl;
    }

}

void IOPractice::setPrintValues(int *idx, double *val, int n) {
    const int beginValues = -10;
    const int endValues = beginValues + n;
    int idxValId = 0;
    for (int i = beginValues; i < endValues; i++) {
        idx[idxValId] = i;
        val[idxValId] = pow(3.14159265, i);
        idxValId++;
    }
}

void IOPractice::inputPractice() {
    // read single integer
}

std::string IOPractice::ltrim(const std::string &str) {
    // make a copy of the string
    std::string s(str);

    // std::ptr_fun: convert a function pointer/object to an equivalent object that can be used as functor!
    /*
     * Input: function pointer
     * return: function object that wraps the function pointer
     * template <typename R, typename Arg>
     * std::function<R(Arg)> ptr_fun(R (*pf) (Arg))
     */


    return std::string();
}

/*
 * static_cast<dest_type> (source)
 * compile time cast e.g. int to float
 * Example1: primitive type type cast
 * <i> implicit: float f = 4.5; int i = f;
 * <ii> explicit: int i = std::static_cast<int> f;
 * Example2: primitive type pointers type cast
 * int a = 10; char c = 'a';
 * // Pass at compile time, but get error during runtime
 * <i> implicit: int *q = (int*)&c;
 * <ii> explicit: int *p = static_cast<int*> (&c)
 * Example3: static cast using conversion operator
 * class myInteger {operator string() ...}
 * myInteger obj(3);
 * string str = static_cast<string>(obj);
 * Example4: inheritance => allow upcast and downcast; need to be public inheritance!
 */


class MyClass {
private:
    int val;
public:
    MyClass() = delete; // Disable the default constructor; creating obj without arguments is invalid
    MyClass(const MyClass&) = delete; // Disable the copy constructor

    MyClass(int val) : val(val) {} // Member initializer List

    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os <<"MyClass(" << obj.val << ")";
    }
};
