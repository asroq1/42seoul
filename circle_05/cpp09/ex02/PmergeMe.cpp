#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    this->_vector = ref._vector;
    this->_list = ref._list;

    return *this;
}

std::vector<int> PmergeMe::insertionSortVector(std::vector<int> &vec, int left,
                                               int right) {
    return vec;
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<int> &vec, int left,
                                           int middle, int right) {
    return vec;
}

std::list<int> PmergeMe::insertionSortList(std::list<int> &lst, int left,
                                           int right) {
    return lst;
}

std::list<int> PmergeMe::mergeSortList(std::list<int> &lst, int left,
                                       int middle, int right) {
    return lst;
}