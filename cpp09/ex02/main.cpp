#include "PmergeMe.hpp"

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