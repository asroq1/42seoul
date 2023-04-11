#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
   private:
    /* data */

   public:
    std::vector<int> _vector;
    std::deque<int> _deque;

    PmergeMe();
    PmergeMe(const PmergeMe &ref);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &ref);

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
