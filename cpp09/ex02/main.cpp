#include "PmergeMe.hpp"


// Function to merge two sorted subvectors into one sorted vector
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    std::vector<int> L;
    std::vector<int> R;

    // Copy data to temporary vectors L[] and R[]
    for (i = 0; i < n1; i++)
        L.push_back(arr[left + i]);
    for (j = 0; j < n2; j++)
        R.push_back(arr[mid + 1 + j]);

    // Merge the temporary vectors back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on the vector
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + right) / 2;

        // Recursive calls to mergeSort for the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print the vector
void printVector(const std::vector<int>& arr) {
    for (std::vector<int>::size_type i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) {

    (void)argc;

    std::vector<int> test;

    for (int i = 1; argv[i]; i++) {
        test.push_back(atoi(argv[i]));
    }
    
    std::cout << "Original array: ";
    printVector(test);

    // Sort the array using merge sort
    mergeSort(test, 0, test.size() - 1);

    std::cout << "Sorted array: ";
    printVector(test);

    return 0;
}


// template <typename T>
// void insertionSort(T &c, size_t size) {
//     size_t i, j;
//     for (i = 1; i < size; i++) {
//         j = i;
//         while (j > 0 && c[j - 1] > c[j]) {
//             std::swap(c[j], c[j - 1]);
//             j = j - 1;
//         }
//     }
// }

// bool parseNumbers(char **argv) {
//     for (int i = 1; argv[i]; i++) {
//         char *end;
//         long number = std::strtol(argv[i], &end, 10);
//         if (*end != '\0' || number < 0 || number > INT_MAX) {
//             return false;
//         }
//     }
//     return true;
// }

// void printVector(const std::vector<int>& vec) {
//     for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
//         std::cout << vec[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int main(int argc, char **argv) {
//     if (argc < 2) {
//         std::cout << "Not enough numbers to sort." << std::endl;
//         return 1;
//     }

//     if (!parseNumbers(argv)) {
//         std::cout << "Invalid input detected." << std::endl;
//     }

    // std::vector<int> test;

    // for (int i = 1; argv[i]; i++) {
    //     test.push_back(atoi(argv[i]));
    // }

//     std::cout << "Before: ";
//     printVector(test);

//     // insertionSort(test, test.size());
//     size_t size = sizeof(test) / sizeof(test[0]);
//     mergeSort(test, 0, size - 1);

//     std::cout << "After: ";
//     printVector(test);

//     return 0;
// }

// int main() {

//     std::clock_t start = std::clock();

//     randomFunction();

//     std::clock_t end = std::clock();

//     double timeinMs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

//     std::cout << "Elapsed time: " << timeinMs << " microseconds." << std::endl;

//     return 0;
// }