#include "whatever.hpp"
#include <iostream>

int main() {
    int x = 6;
    int y = 9;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    swap(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    float a = 4.2;
    float b = 1.9;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swap(a,b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    int minRes = min(x, y);
    int maxRes = max(x, y);

    std::cout << "Min: " << minRes << std::endl;
    std::cout << "Max: " << maxRes << std::endl;

    return 0;
}