#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    this->_vector = ref._vector;
    this->_list = ref._list;

    return *this;
}

std::vector<int> PmergeMe::insertionSortVector(std::vector<int> &vec) {
    int j, key;  // 현재 키값의 인덱스 -1
    for (int i = 1; i < vec.size(); i++) {
        key = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
    }
    vec[j + 1] = key;
    return vec;
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<int> &vec, int left,
                                           int middle, int right) {
    return vec;
}

std::list<int> PmergeMe::insertionSortList(std::list<int> &lst) {
    int key;
    std::list<int>::iterator itr = ++lst.begin();

    for (; itr != lst.end(); itr++) {
        key = *itr;
        std::list<int>::iterator j = prev(itr);
        while (j != lst.begin() && *j > key) {
            *next(j) = *j;
            j--;
        }
        if (*j > key) {
            lst.front() = key;
        } else {
            *next(j) = key;
        }
    }

    return lst;
}

// original
// void insertionSort(list<int> &lst) {
//    list<int>::iterator it = ++lst.begin();
//    for (; it != lst.end(); ++it) {
//        int key = *it;
//        list<int>::iterator j = prev(it);
//        while (j != lst.begin() && *j > key) {
//            *(next(j)) = *j;
//            --j;
//        }
//        if (*j > key) {
//            lst.front() = key;
//        } else {
//            *(next(j)) = key;
//        }
//    }
//}

std::list<int> PmergeMe::mergeSortList(std::list<int> &lst, int left,
                                       int middle, int right) {
    return lst;
}