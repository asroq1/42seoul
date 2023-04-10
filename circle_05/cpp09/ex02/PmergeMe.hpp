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
    PmergeMe(const PmergeMe &ref);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &ref);

    std::vector<int> insertionSortVector(std::vector<int> &vec, int left,
                                         int right);
    std::vector<int> mergeSortVector(std::vector<int> &vec, int left,
                                     int middle, int right);

    std::list<int> insertionSortList(std::list<int> &lst, int left, int right);
    std::list<int> mergeSortList(std::list<int> &lst, int left, int middle,
                                 int right);
};

#endif
