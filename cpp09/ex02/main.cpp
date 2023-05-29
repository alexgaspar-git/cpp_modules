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
            ++leftIt;
        } else {
            *tempIt = *rightIt;
            ++rightIt;
        }
        ++tempIt;
    }

    while (leftIt <= mid) {
        *tempIt = *leftIt;
        ++leftIt;
        ++tempIt;
    }

    while (rightIt <= right) {
        *tempIt = *rightIt;
        ++rightIt;
        ++tempIt;
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

static bool parseNumbers(char **argv) {
    for (int i = 1; argv[i]; i++) {
        char *end;
        long number = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || number < 0 || number > INT_MAX) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Not enough numbers to sort." << std::endl;
        return 1;
    }

    if (!parseNumbers(argv)) {
        std::cout << "Invalid input detected." << std::endl;
        return 2;
    }

    std::vector<int> vec;
    for (int i = 1; argv[i]; i++) {
        vec.push_back(atoi(argv[i]));
    }

    std::deque<int> deq;
    for (int i = 1; argv[i]; i++) {
        deq.push_back(atoi(argv[i]));
    }

    std::cout << "Before: ";

    printContainer(vec);

    double vecTime = sort(vec);
    double deqTime = sort(deq);

    std::cout << "After: ";

    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << "ms" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << "ms" << std::endl;

    return 0;
}