// #include "easyfind.hpp"
#include "Span.hpp"
#include <iterator>
#include <list>
#include <vector>

// void leaker() { system("leaks a.out"); }
int randomf() { return (int)(rand()); }

int main() {
    // atexit(leaker);

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span extra = Span(11000);
    std::vector<int> tmp(1000);
    std::generate(tmp.begin(), tmp.end(), randomf);

    extra.addNumber(tmp.begin(), tmp.end());
    // extra.addNumber(1);
    std::cout << extra.shortestSpan() << std::endl;
    std::cout << extra.longestSpan() << std::endl;

    return 0;
}