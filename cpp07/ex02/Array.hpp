#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstddef>
# include <exception>



template <typename T> class Array {
private:
    T *_elem;
    unsigned int _size;
public:
    Array(unsigned int n);

    Array();
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);

    T &operator[](unsigned int index);

    unsigned int size();

};

#include "Array.tpp"


#endif