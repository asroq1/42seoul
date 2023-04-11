

#include <ctime>
#include <iomanip>

#include "PmergeMe.hpp"

int main(int argc, const char** argv) {
    PmergeMe tester;

    for (int i = 1; i < argc; i++) {
        int value = std::atoi(argv[i]);
        tester._vector.push_back(value);
        tester._deque.push_back(value);
    }

    clock_t start = clock();

    tester.mergeInsertionSortDeque(tester._deque);

    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // 너무 짧은 값은 지수 표기법으로 나오기 때문에 fixed 플래그로 바꿔준다.
    std::cout << "deque : " << std::fixed << std::setprecision(6) << time
              << std::endl;

    start = clock();

    tester.mergeInsertionSort(tester._vector);

    end = clock();

    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // 너무 짧은 값은 지수 표기법으로 나오기 때문에 fixed 플래그로 바꿔준다.
    std::cout << "vector : " << std::fixed << std::setprecision(6) << time
              << std::endl;

    // std::cout << "=========tester============" << std::endl;
    // for (int value : tester._vector) {
    //     std::cout << value << " ";
    // }
    // std::cout << "original" << std::endl;

    // tester.mergeInsertionSort(tester._vector);

    // for (int value : tester._vector) {
    //     std::cout << value << " ";
    // }
    // std::cout << "after" << std::endl;
    // std::cout << "=========tester============" << std::endl;

    // std::cout << "=========deque============" << std::endl;
    // for (int value : tester._deque) {
    //     std::cout << value << " ";
    // }
    // std::cout << "original" << std::endl;

    // tester.mergeInsertionSortDeque(tester._deque);

    // for (int value : tester._deque) {
    //     std::cout << value << " ";
    // }
    // std::cout << "after" << std::endl;
    // std::cout << "=========deque============" << std::endl;

    return 0;
}