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
        int i = 0;
        std::cout << "stack[" << i << "] :" << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    std::cout << "another stack" << std::endl;
    MutantStack<int> s(mstack);

    MutantStack<int>::iterator anotherIt = s.begin();
    MutantStack<int>::iterator anotherIte = s.end();
    ++anotherIt;
    --anotherIt;
    while (anotherIt != anotherIte) {
        int i = 0;
        std::cout << "stack[" << i << "] :" << *anotherIt << std::endl;
        ++anotherIt;
    }
    return 0;
}