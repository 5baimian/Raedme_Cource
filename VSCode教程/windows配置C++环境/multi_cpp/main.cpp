// main.cpp
#include <iostream>
#include "include/Calculator.h"

int main(int argc, char **argv) {
    double a = 10.0, b = 5.0;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    Calculator calc;
    // 
    std::cout << "Addition: " << calc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(a, b) << std::endl;
    std::cout << "Division: " << calc.divide(a, b) << std::endl;

    return 0;
}