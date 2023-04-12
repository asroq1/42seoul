

#include <ctime>
#include <iomanip>

#include "PmergeMe.hpp"

int main(int argc, const char** argv) {
    PmergeMe tester;

    if (argc == 1) {
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (!isdigit(argv[i][0])) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        int value = std::atoi(argv[i]);
        tester._vector.push_back(value);
        tester._deque.push_back(value);
    }

    std::cout << "Before : ";
    for (size_t i = 0; i < tester._vector.size(); i++) {
        std::cout << tester._vector[i] << " ";
    }
    std::cout << std::endl;

    // vector
    clock_t start = clock();
    tester.mergeInsertionSort(tester._vector);
    clock_t end = clock();

    std::cout << "After : ";
    for (size_t i = 0; i < tester._vector.size(); i++) {
        std::cout << tester._vector[i] << " ";
    }

    std::cout << std::endl;
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // 너무 짧은 값은 지수 표기법으로 나오기 때문에 fixed 플래그로 바꿔준다.
    std::cout << "vector : " << std::fixed << std::setprecision(6) << time
              << std::endl;

    // deque
    start = clock();
    tester.mergeInsertionSortDeque(tester._deque);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "deque  : " << std::fixed << std::setprecision(6) << time
              << std::endl;

    return 0;
}