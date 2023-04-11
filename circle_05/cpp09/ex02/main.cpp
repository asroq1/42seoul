

#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, const char** argv) {
    PmergeMe vector;

    for (int i = 1; i < argc; i++) {
        int value = std::atoi(argv[i]);
        vector._vector.push_back(value);
    }

    for (int value : vector._vector) {
        std::cout << "val : " << value << " " << std::endl;
    }

    vector.mergeInsertionSort(vector._vector, 0, 5);

    for (int value : vector._vector) {
        std::cout << "after : " << value << " " << std::endl;
    }

    std::cout << std::endl;

    return 0;
}