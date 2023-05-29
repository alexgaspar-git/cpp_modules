#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <limits.h>
#include <cstdlib>
#include <deque>
#include <vector>

#define THRESHOLD 10

template<typename T>
void merge(typename T::iterator left, typename T::iterator mid, typename T::iterator right);

template<typename T>
void mergeSort(T &c, typename T::iterator left, typename T::iterator right);

template <typename T>
void insertionSort(T &c, size_t size);

template <typename T>
double sort(T &c);

template<typename T>
void printContainer(T &c);

#endif