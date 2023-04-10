#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe {
   private:
    /* data */

   public:
    PmergeMe();
    PmergeMe(const PmergeMe& ref);
    ~PmergeMe();

    PmergeMe& operator=(const PmergeMe& ref);
};

#endif
