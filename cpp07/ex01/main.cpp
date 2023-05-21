#include "iter.hpp"
#include <iostream>

void printNum(int num) {
    std::cout << num << " ";
}

void changeNum(int &num) {
    num = 42;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};

    iter(intArray, 5, printNum);
    std::cout << std::endl;
    iter(intArray, 5, changeNum);
    iter(intArray, 5, printNum);

    return 0;
}