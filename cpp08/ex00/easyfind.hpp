#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <list>

class ValueNotFoundException : public std::exception {
public:
    const char *what() const throw();
};

template <typename T> typename T::iterator easyfind(T &t, int n);

#include "easyfind.tpp"

#endif
