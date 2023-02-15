#include "Span.hpp"
#include <iterator>
#include <list>
#include <vector>

// void leaker() { system("leaks a.out"); }
int randomf() { return (int)(rand()); }

int main() {
    // atexit(leaker);

    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
<<<<<<< HEAD
        sp.addNumber(11);

=======
        std::cout << "sp.shortestSpan() :" << sp.shortestSpan() << std::endl;
        std::cout << "sp.longestSpan() :" << sp.longestSpan() << std::endl;
        std::cout << std::endl;
>>>>>>> dcaf7d81b3613f90e638aa3f6f0d17ca28390fae

        Span extra = Span(11000);
        std::vector<int> tmp(10000);
        std::generate(tmp.begin(), tmp.end(), randomf);
        extra.addNumber(tmp, 10000);
<<<<<<< HEAD
        extra.addNumber(tmp,10000);
        std::cout << extra.shortestSpan() << std::endl;
        std::cout << extra.longestSpan() << std::endl;
=======
        // extra.addNumber(tmp, 1001);
        std::cout << "extra.shortestSpan() :" << extra.shortestSpan()
                  << std::endl;
        std::cout << "extra.shortestSpan() :" << extra.longestSpan()
                  << std::endl;
>>>>>>> dcaf7d81b3613f90e638aa3f6f0d17ca28390fae
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}