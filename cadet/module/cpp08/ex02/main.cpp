#include "MutantStack.hpp"
#include <iostream>
int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top() : " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "mstack.size() : " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Another stack" << std::endl;
    MutantStack<int> s(mstack);

    MutantStack<int>::iterator anotherIt = s.begin();
    MutantStack<int>::iterator anotherIte = s.end();
    ++anotherIt;
    --anotherIt;
    while (anotherIt != anotherIte) {
        std::cout << *anotherIt << std::endl;
        ++anotherIt;
    }

    // std::cout << "Original stack" << std::endl;
    // std::stack<int> origin(mstack);

    // std::stack<int>::iterator oriIt = origin.begin();
    // std::stack<int>::iterator oriIte = origin.end();
    // ++oriIt;
    // --oriIt;
    // while (oriIt != oriIte) {
    //     std::cout << *oriIt << std::endl;
    //     ++oriIt;
    // }
    return 0;
}