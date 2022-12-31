/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:40:12 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/30 12:14:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

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
    if (isInf()) {
        std::cout << "isInf" << std::endl;
        printInf();
        return;
    }
    if (isChar(input)) {
        std::cout << "is Char" << std::endl;
        this->_charValue = static_cast<char>(input[0]);
        printChar(this->_charValue);
        return;
    } else if (isNan()) {
        std::cout << "isNaN" << std::endl;
        printNan();
        return;
    } else if (isInf()) {

    } else if (isInt(input)) {
        std::cout << "is Int" << std::endl;
        printInt(this->_parsedValue);
        return;
    } else if (isFloat()) {
        std::cout << "is Float" << std::endl;
        printFloat();
    } else if (isDouble()) {
        std::cout << "is Double" << std::endl;
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

bool Convertor::isInt(std::string input ) {
    this->_intValue = static_cast<int>(this->_parsedValue);
    std::cout << " valui " << this->_intValue << std::endl;
    if (static_cast<std::string>(this->_pos).length() != 0) {
        return false;
    }
    if (this->_intValue > INT_MAX || this->_intValue < INT_MIN) {
        std::cout << "error" << std::endl;
        return false;
    }
    return true;
}

bool Convertor::isFloat() {
    int strPos = static_cast<std::string>(this->_pos).length() - 1;
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
    std::cout << "test" << this->_parsedValue << std::endl;
    if (n < 127 && n >= 32) {
        std::cout << "char : '" << static_cast<char>(n) << "'" << std::endl;
    } else if (n >= 0 && n < 32) {
        std::cout << "char : Non displayable" << std::endl;
    } else if (isnan(static_cast<float>(n)) || n <= 0 || n > 126) {
        std::cout << "char : impossible" << std::endl;
    }
    if (n > INT_MAX || n < INT_MIN) {
        std::cout << "int : impossible" << std::endl;
    } else {
        std::cout << "int : " << static_cast<int>(n) << std::endl;
    }
    std::cout << "float : " << static_cast<float>(this->_parsedValue) << "f"
              << std::endl;
    std::cout << "double : " << static_cast<double>(n) << ".0" << std::endl;
}

void Convertor::printFloat() {
    if (static_cast<char>(this->_parsedValue) <= 0) {
        std::cout << "char : Non displayable" << std::endl;
    } else {
        std::cout << "char : '" << static_cast<char>(this->_parsedValue) << "'"
                  << std::endl;
    }
    std::cout << "int : " << static_cast<int>(this->_parsedValue) << std::endl;
    std::cout << "float : " << static_cast<float>(this->_parsedValue) << ".0f"
              << std::endl;
    std::cout << "double : " << static_cast<double>(this->_parsedValue) << ".0"
              << std::endl;
}

void Convertor::printDouble() {
    std::cout << "char : '" << static_cast<char>(this->_parsedValue) << "'"
              << std::endl;
    std::cout << "int : " << static_cast<int>(this->_parsedValue) << std::endl;
    std::cout << "float : " << static_cast<float>(this->_parsedValue) << ".0f"
              << std::endl;
    std::cout << "double : " << static_cast<double>(this->_parsedValue) << ".0"
              << std::endl;
}

void Convertor::printNan() {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}

void Convertor::printInf() {
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    if (static_cast<int>(this->_parsedValue) < 0) {
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
    } else {
        std::cout << "float : inff" << std::endl;
        std::cout << "double : inf" << std::endl;
    }
}