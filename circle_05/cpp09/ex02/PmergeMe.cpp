#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    this->_vector = ref._vector;
    this->_deque = ref._deque;

    return *this;
}

void PmergeMe::insertionSortVector(std::vector<int> &vec) {
    int j, key = 0;  // 현재 키값의 인덱스 -1
    for (int i = 1; i < vec.size(); i++) {
        key = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

 
void PmergeMe::mergeSortVector(std::vector<int> &vec, std::vector<int> &left,
                               std::vector<int> &right) {
    int i = 0;
    int j = 0;
    int k = 0;  // i 왼쪽 벡터 j오른쪽 벡터 k 병합된 벡터

    // 왼쪽 벡터와 오른쪽 벡터 원소를 비교해 작은 원소를 병합된 벡터에 삽입
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
        }
    }

    // 왼쪽 벡터에 남은 나머지 값 복사
    while (i < left.size()) {
        vec[k++] = left[i++];
    }
    // 오른쪽 벡터에 남은 나머지 값 복사
    while (j < right.size()) {
        vec[k++] = right[j++];
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int> &vec) {
    if (vec.size() <= 1) {
        std::cout << "not a numbers" << std::endl;
        return;
    }
    if (vec.size() <= 10) {  // elements가 10개 이하는 inserction
        insertionSortVector(vec);
    } else {
        int mid = vec.size() / 2;
        std::vector<int> left(vec.begin(), vec.begin() + mid);
        std::vector<int> right(vec.begin() + mid, vec.end());

        mergeInsertionSort(left);
        mergeInsertionSort(right);
        mergeSortVector(vec, left, right);
    }
}

void PmergeMe::insertionSortDeque(std::deque<int> &deq) {
    int j, key = 0;  // 현재 키값의 인덱스 -1
    for (int i = 1; i < deq.size(); i++) {
        key = deq[i];
        j = i - 1;
        while (j >= 0 && deq[j] > key) {
            deq[j + 1] = deq[j];
            j--;
        }
        deq[j + 1] = key;
    }
}

void PmergeMe::mergeSortDeque(std::deque<int> &deq, std::deque<int> &left,
                              std::deque<int> &right) {
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            deq.push_back(left.front());
            left.pop_front();
        } else {
            deq.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        deq.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        deq.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &deq) {
    // 2개 이상의 정렬이 아닌 경우 종료
    if (deq.size() <= 1) {
        return;
    }
    if (deq.size() <= 2) {  // elements가 10개 이하는 inserction
        insertionSortDeque(deq);
    } else {
        int mid = deq.size() / 2;
        std::deque<int> left;
        std::deque<int> right;

        for (int i = 0; i < mid; ++i) {
            left.push_back(deq[i]);
        }

        for (int j = mid; j < deq.size(); ++j) {
            right.push_back(deq[j]);
        }
        mergeInsertionSortDeque(left);
        mergeInsertionSortDeque(right);
        // 기존 deque에 쌓인 값때문에 비워주고 merge해야함
        deq.clear();
        mergeSortDeque(deq, left, right);
    }
}