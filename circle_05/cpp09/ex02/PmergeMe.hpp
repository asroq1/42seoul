#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
   private:
    std::vector<int> _vector;
    std::deque<int> _deque;

   public:
    PmergeMe();
    PmergeMe(const PmergeMe &ref);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &ref);

    // get set
    std::vector<int> get_vector() { return _vector; }
    std::deque<int> get_deque() { return this->_deque; }

    void set_deque(int _deque) { this->_deque = _deque; }
    void set_vector(std::vector<int> _vector) { _vector = _vector; }

    void insertionSortVector(std::vector<int> &vec);
    void mergeSortVector(std::vector<int> &vec, std::vector<int> &left,
                         std::vector<int> &right);
    void mergeInsertionSort(std::vector<int> &vec);

    void insertionSortDeque(std::deque<int> &deq);
    void mergeSortDeque(std::deque<int> &deq, std::deque<int> &left,
                        std::deque<int> &right);
    void mergeInsertionSortDeque(std::deque<int> &deq);
};
#endif
