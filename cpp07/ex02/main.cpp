#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> arr1;
    Array<int> arr2(5);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i + 1;

    Array<int> arr3 = arr2;
    arr1 = arr2;

    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;

    return 0;
}
