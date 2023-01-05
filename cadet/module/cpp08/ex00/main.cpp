#include "easyfind.hpp"
#include <iterator>
#include <vector>

int main(void) {
    std::vector<int> v;

    v.push_back(42);
    v.push_back(52);
    v.push_back(62);
    v.push_back(72);

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "v[" << i << "]: " << v[i] << std::endl;
    }
    std::vector<int>::iterator itr = easyfind(v, 42);
    std::cout << "itr : " << *itr << std::endl;
    try {
        easyfind(v, 4);
        easyfind(v, 2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}