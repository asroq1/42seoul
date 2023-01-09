#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int input)
{
    typename T::iterator itr;
    itr = std::find(container.begin(), container.end(), input);
    if (itr == container.end())
        throw std::exception();
    return (itr);
}
#endif
