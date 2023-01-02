/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:40:12 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/02 17:07:27 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"
#include <sstream>

Convertor::Convertor() {}

Convertor::Convertor(const Convertor &ref) { *this = ref; };

Convertor::~Convertor() {}

Convertor &Convertor::operator=(const Convertor &ref) {
    (void)ref;
    return *this;
}

void Convertor::setValue(std::string input, char *av) {
    this->_value = av;
    this->_parsedValue = std::strtod(av, &this->_pos);
    this->_origin = static_cast<std::string>(av);

    if (isChar(input)) {
        this->_charValue = static_cast<char>(input[0]);
        printChar(this->_charValue);
        return;
    } else if (isInf()) {
        printInf(av);
        return;
    } else if (isNan()) {
        printNan();
        return;
    } else if (isInt()) {
        printInt(this->_parsedValue);
        return;
    } else if (isFloat()) {
        printFloat();
    } else if (isDouble()) {
        printDouble();
    }
}

bool Convertor::isNan() {
    if (isnan(this->_parsedValue)) {
        return true;
    } else if (static_cast<std::string>(this->_pos).length() > 1 ||
               (static_cast<std::string>(this->_pos).length() == 1 &&
                this->_pos[0] != 'f')) {

        return true;
    }
    return false;
}

bool Convertor::isInf() {
    if (isinf(this->_parsedValue)) {
        return true;
    } else if (static_cast<std::string>(this->_pos).length() > 1 ||
               (static_cast<std::string>(this->_pos).length() == 1 &&
                this->_pos[0] != 'f')) {
        return true;
    }
    return false;
}

bool Convertor::isChar(std::string input) {
    if (input.length() == 1 && isdigit(input[0]) == 0) {
        return true;
    }
    return false;
}

bool Convertor::isInt() {
    std::string::size_type ori;
    ori = this->_origin.find('.');
    this->_intValue = static_cast<int>(this->_parsedValue);
    if (static_cast<std::string>(this->_pos).length() != 0) {
        return false;
    }
    if (this->_intValue > INT_MAX || this->_intValue < INT_MIN) {
        return false;
    }
    if (ori == std::string::npos)
        return true;
    else
        return false;
}

bool Convertor::isFloat() {

    int strPos = static_cast<std::string>(this->_pos).length() - 1;
    if (strPos < 0)
        return false;
    if (static_cast<std::string>(this->_pos).at(strPos) != 'f' &&
        static_cast<std::string>(this->_pos).length() > 6) {
        return false;
    }
    return true;
}

bool Convertor::isDouble() {

    if (static_cast<std::string>(this->_pos).length() > 0) {
        return false;
    }
    return true;
}

void Convertor::printChar(char c) {
    if (c > 127 || c < 32) {
        std::cout << "char : Non displayable" << std::endl;
    } else {
        std::cout << "char : '" << c << "'" << std::endl;
    }
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void Convertor::printInt(int n) {
    std::stringstream ss;
    std::string tmp;

    int i = static_cast<int>(this->_parsedValue);

    if (n < 127 && n >= 32) {
        std::cout << "char : '" << static_cast<char>(n) << "'" << std::endl;
    } else if (n >= 0 && n < 32) {
        std::cout << "char : Non displayable" << std::endl;
    } else if (isnan(static_cast<float>(n)) || n <= 0 || n > 126) {
        std::cout << "char : impossible" << std::endl;
    }
    if (i == INT_MIN) {
        ss << i;
        tmp = ss.str();
        if (tmp.compare(this->_origin.substr(0, 11))) {
            std::cout << "int : impossible" << std::endl;
        } else {
            std::cout << "int : " << static_cast<int>(n) << std::endl;
        }
    } else {
        std::cout << "int : " << static_cast<int>(n) << std::endl;
    }
    if (static_cast<int>(this->_parsedValue) == 0) {
        std::cout << "float : 0.0f" << std::endl;
        std::cout << "double : 0.0" << std::endl;
    } else {
        std::cout << "float : " << static_cast<float>(this->_parsedValue)
                  << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(this->_parsedValue)
                  << ".0" << std::endl;
    }
    std::cout << std::endl;
}

void Convertor::printFloat() {
    std::string::size_type ori;
    ori = this->_origin.find('.');

    if (static_cast<char>(this->_parsedValue) <= 0) {
        std::cout << "char : Non displayable" << std::endl;
    } else {
        std::cout << "char : '" << static_cast<char>(this->_parsedValue) << "'"
                  << std::endl;
    }
    std::cout << "int : " << static_cast<int>(this->_parsedValue) << std::endl;
    if (static_cast<int>(this->_parsedValue) ==
        static_cast<float>(this->_parsedValue)) {
        std::cout << "float : " << static_cast<float>(this->_parsedValue)
                  << ".0f" << std::endl;
    } else {
        std::cout << "float : " << static_cast<float>(this->_parsedValue) << "f"
                  << std::endl;
    }
    std::cout << "double : " << static_cast<double>(this->_parsedValue)
              << std::endl;
}

void Convertor::printDouble() {
    int n = static_cast<int>(this->_parsedValue);

    if (n < 127 && n >= 32) {
        std::cout << "char : '" << static_cast<char>(n) << "'" << std::endl;
    } else if (n >= 0 && n < 32) {
        std::cout << "char : Non displayable" << std::endl;
    } else if (isnan(static_cast<float>(n)) || n <= 0 || n > 126) {
        std::cout << "char : impossible" << std::endl;
    }
    std::cout << "int : " << static_cast<int>(this->_parsedValue) << std::endl;
    if (static_cast<int>(this->_parsedValue) ==
        static_cast<float>(this->_parsedValue)) {
        std::cout << "float : " << static_cast<float>(this->_parsedValue)
                  << ".0f" << std::endl;
    } else {
        std::cout << "float : " << static_cast<float>(this->_parsedValue) << "f"
                  << std::endl;
    }
    if (static_cast<int>(this->_parsedValue) ==
        static_cast<double>(this->_parsedValue)) {
        std::cout << "double : " << static_cast<double>(this->_parsedValue)
                  << ".0" << std::endl;

    } else {
        std::cout << "double : " << static_cast<double>(this->_parsedValue)
                  << std::endl;
    }
}

void Convertor::printNan() {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}

void Convertor::printInf(char *av) {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    if (av[0] == '-' && isinf(this->_parsedValue)) {
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
    } else if (isinf(this->_parsedValue)) {
        std::cout << "float : inff" << std::endl;
        std::cout << "double : inf" << std::endl;
    } else {
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
    }
}