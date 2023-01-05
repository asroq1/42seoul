
#include "Span.hpp"

Span::Span() { throw std::exception(); };

Span::Span(unsigned int n) {
    this->_maxSize = n;
    std::cout << "CONS SIZE :" << this->_v.size() << std::endl;
};
Span::~Span(){};

Span::Span(const Span &ref) {
    this->_maxSize = ref._maxSize;
    this->_v = ref._v;
};

Span &Span::operator=(const Span &ref) {
    if (this != &ref) {
        this->_maxSize = ref._maxSize;
        this->_v = ref._v;
    }
    return *this;
};

void Span::addNumber(unsigned int n) {
    if (this->_v.size() > this->_maxSize) {
        throw std::exception();
    }
    this->_v.push_back(n);
};

void Span::addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end) {
    std::vector<int> tmp;
    // if (this->_v.size() < v.size()) {
    //     std::cout << "Extra" << this->_v.size() << std::endl;
    //     std::cout << "tmp" << v.size() << std::endl;

    //     std::cout << "test" << std::endl;
    // }

    this->_v.insert(this->_v.end(), start, end);
    std::cout << "zise :" << this->_v.size() << std::endl;
};

unsigned int Span::shortestSpan() {
    if (this->_v.size() <= 1) {
        throw std::exception();
    }
    unsigned int result;
    unsigned int min;

    sort(this->_v.begin(), this->_v.end());
    min = this->_v[1] - this->_v[0];
    for (size_t i = 0; i < this->_v.size(); i++) {
        result = this->_v[i + 1] - this->_v[i];
        if (result < min) {
            min = result;
        }
    }
    return min;
};

unsigned int Span::longestSpan() {
    if (this->_v.size() <= 1) {
        throw std::exception();
    }
    unsigned int result;
    sort(this->_v.begin(), this->_v.end());
    result = *std::max_element(this->_v.begin(), this->_v.end()) -
             *std::min_element(this->_v.begin(), this->_v.end());

    return result;
};
