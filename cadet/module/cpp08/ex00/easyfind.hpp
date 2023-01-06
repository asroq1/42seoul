#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int input) {
    // 파라미터에 T의해 T의 의미가 모호해져 컴파일러가 힘들어함 typename을
    // 붙여서 재선언 해준다.
    typename T::iterator itr;
    itr = std::find(container.begin(), container.end(), input);
    if (itr == container.end()) {
        throw std::exception();
    }
    return itr;
}
#endif
