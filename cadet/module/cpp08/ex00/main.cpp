#include "easyfind.hpp"
#include <iterator>
#include <list>
#include <vector>

int main(void) {
    std::vector<int> v;
    std::list<int> lst;

    v.push_back(42);
    v.push_back(52);
    v.push_back(62);
    v.push_back(72);

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "v[" << i << "]: " << v[i] << std::endl;
    }
    std::cout << std::endl;

    std::vector<int>::iterator itr = easyfind(v, 42);
    std::cout << "itr : " << *itr << std::endl;
    try {
        easyfind(v, 4);
        easyfind(v, 2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    std::list<int>::iterator lstItr;
    for (lstItr = lst.begin(); lstItr != lst.end(); lstItr++) {
        int i = 0;
        std::cout << "lst[" << i++ << "]: " << *lstItr << std::endl;
    }
    std::cout << std::endl;

    lstItr = easyfind(lst, 3);
    std::cout << "list itr : " << *lstItr << std::endl;
    try {
        easyfind(lst, 42);
        easyfind(lst, 24);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}