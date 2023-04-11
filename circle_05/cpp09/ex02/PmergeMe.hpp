#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>

class PmergeMe {
   private:
    /* data */

   public:
    std::vector<int> _vector;
    std::list<int> _list;

    PmergeMe();
    // PmergeMe(argv);
    PmergeMe(const PmergeMe &ref);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &ref);

    std::vector<int> insertionSortVector(std::vector<int> &vec);
    std::vector<int> mergeSortVector(std::vector<int> &vec);
    std::vector<int> mergeVector(std::vector<int> &vec, int left, int mid,
                                 int right);
    std::vector<int> mergeInsertionSort(std::vector<int> &vec, int left,
                                        int right);
    std::list<int> insertionSortList(std::list<int> &lst);
    std::list<int> mergeSortList(std::list<int> &lst, int left, int middle,
                                 int right);
};

#endif
