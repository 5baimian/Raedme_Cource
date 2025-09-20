#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    // 构造函数和析构函数（如果需要，可以添加）
    Calculator() = default;
    ~Calculator() = default;

    // 加法
    double add(double a, double b);

    // 减法
    double subtract(double a, double b);

    // 乘法
    double multiply(double a, double b);

    // 除法
    double divide(double a, double b);
};

#endif // CALCULATOR_H
