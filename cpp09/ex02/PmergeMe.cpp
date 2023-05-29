#include "PmergeMe.hpp"

template<typename T>
void merge(typename T::iterator left, typename T::iterator mid, typename T::iterator right) {
    T temp(left, right + 1);
    typename T::iterator tempIt = temp.begin();
    typename T::iterator leftIt = left;
    typename T::iterator rightIt = mid + 1;

    while (leftIt <= mid && rightIt <= right) {
        if (*leftIt <= *rightIt) {
            *tempIt = *leftIt;
            leftIt++;
        } else {
            *tempIt = *rightIt;
            rightIt++;
        }
        ++tempIt;
    }

    while (leftIt <= mid) {
        *tempIt = *leftIt;
        leftIt++;
        tempIt++;
    }

    while (rightIt <= right) {
        *tempIt = *rightIt;
        rightIt++;
        tempIt++;
    }

    std::copy(temp.begin(), temp.end(), left);
}

template<typename T>
void mergeSort(T &c, typename T::iterator left, typename T::iterator right) {
    if (left < right) {
        typename T::iterator mid = left + (right - left) / 2;
        mergeSort(c, left, mid);
        mergeSort(c, mid + 1, right);
        merge<T>(left, mid, right);
    }
}

template <typename T>
void insertionSort(T &c, size_t size) {
    size_t i, j;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && c[j - 1] > c[j]) {
            std::swap(c[j], c[j - 1]);
            j = j - 1;
        }
    }
}

template <typename T>
double sort(T &c) {
    std::clock_t start = std::clock();

    size_t size = c.size();

    if (size <= THRESHOLD) {
        insertionSort(c, size);
    } else {
        mergeSort(c, c.begin(), c.end() - 1);
    }

    std::clock_t end = std::clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    return time;
}

template<typename T>
void printContainer(T &c) {
    typename T::const_iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template void merge<std::vector<int> >(std::vector<int>::iterator, std::vector<int>::iterator, std::vector<int>::iterator);
template void merge<std::deque<int> >(std::deque<int>::iterator, std::deque<int>::iterator, std::deque<int>::iterator);

template void mergeSort<std::vector<int> >(std::vector<int>&, std::vector<int>::iterator, std::vector<int>::iterator);
template void mergeSort<std::deque<int> >(std::deque<int>&, std::deque<int>::iterator, std::deque<int>::iterator);

template void insertionSort<std::vector<int> >(std::vector<int>&, size_t);
template void insertionSort<std::deque<int> >(std::deque<int>&, size_t);

template double sort<std::vector<int> >(std::vector<int>&);
template double sort<std::deque<int> >(std::deque<int>&);

template void printContainer<std::vector<int> >(std::vector<int>&);
template void printContainer<std::deque<int> >(std::deque<int>&);
