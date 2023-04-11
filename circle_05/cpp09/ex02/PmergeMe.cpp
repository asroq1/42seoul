#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

// PmergeMe::PmergeMe(argv) {}

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

std::vector<int> PmergeMe::mergeVector(std::vector<int> &vec, int left, int mid,
                                       int right) {
    int leftSize = mid - left + 1;  // 왼쪽 벡터 크기
    int rightSize = right - mid;    // 오른쪽 벡터 크기

    // 값을 임시로 저장할 tmp 벡터
    std::vector<int> leftVector(leftSize);
    std::vector<int> rightVector(rightSize);

    // 왼쪽 벡터 부분 복사
    for (int i = 0; i < leftSize; i++) {
        leftVector[i] = vec[left + i];
    }
    // 오른쪽 벡터 부분 복사
    for (int i = 0; i < rightSize; i++) {
        rightVector[i] = vec[right + i];
    }

    int i, j = 0;  // i는 왼쪽 임시 벡터 인덱스, j는 오른쪽
    int k = left;  // 오리지널 벡터의 인덱스

    // 두 tmp의 값을 비교해 오리지널 벡터에 저장
    while (i < leftSize && j < rightSize) {
        if (leftVector[i] <= rightVector[j]) {
            vec[k++] = leftVector[i++];
        } else {
            vec[k++] = rightVector[j++];
        }
    }

    // 왼쪽 임시 벡터의 값을 오리지널에 저장
    while (i < leftSize) {
        vec[k++] = leftVector[i++];
    }
    // 오른쪽 임시 벡터의 값을 오리지널에 저장
    while (j < rightSize) {
        vec[k++] = rightVector[j++];
    }
    return vec;
}

// std::vector<int> PmergeMe::mergeSortVector(std::vector<int> &vec) {
//     int size = vec.size();
//     int mid = size / 2;
//     if (size <= 1) {
//         return;
//     }

//    std::vector<int> left(vec.begin(), vec.begin() + mid);
//    std::vector<int> right(vec.begin() + mid, vec.end());

//    mergeSortVector(left);
//    mergeSortVector(right);

//    return mergeVector(ve);
//}

std::vector<int> PmergeMe::mergeInsertionSort(std::vector<int> &vec, int left,
                                              int right) {
    if (right - left + 1 <= 10) {  // elements가 10개 이하는 inserction
        insertionSortVector(vec);
    } else {
        int mid = (left + right) / 2;
        mergeInsertionSort(vec, left, mid);
        mergeInsertionSort(vec, mid + 1, right);
        mergeVector(vec, left, mid, right);
    }
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