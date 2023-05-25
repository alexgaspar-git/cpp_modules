#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);


    try {
        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        std::cout << "Found value in vector at index: " << std::distance(vec.begin(), vecIt) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator lstIt = easyfind(lst, 25);
        std::cout << "Found value in list at index: " << std::distance(lst.begin(), lstIt) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}