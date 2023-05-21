#include "Array.hpp"

template <typename T> Array<T>::Array() : _elem(NULL), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _size(n) {
    _elem = new T[n];
    for (unsigned int i = 0; i < _size; i++) {
        _elem[i] = T();
    }
}

template <typename T> Array<T>::Array(const Array<T> &other) : _size(other._size) {
    _elem = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _elem[i] = other._elem[i];
    }
}

template <typename T> Array<T>::~Array() {
    delete[] _elem;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
    T *newElem = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++) {
        newElem[i] = other._elem[i];
    }
    delete[] _elem;
    _size = other._size;
    _elem = newElem;
    return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int n) {
    if (n > _size)
        throw std::exception();
    return _elem[n];
}

template <typename T> unsigned int Array<T>::size() {
    return _size;
}
