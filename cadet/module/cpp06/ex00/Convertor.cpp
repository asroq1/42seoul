/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:40:12 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/28 17:59:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

Convertor::Convertor() {}

Convertor::Convertor(const Convertor &ref) {}

Convertor::~Convertor() {}

Convertor &Convertor::operator=(const Convertor &ref) {}

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

    } else if (isInt()) {
        std::cout << "is Int" << std::endl;
        printInt(this->_parsedValue);
        return;
    }

    // else if (isFloat(input)) {
    //     this->_floatValue = input;
    // } else if (isDouble(input)) {
    //     this->_doubleValue = input;
    // } else if () {
    // }
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
    if (static_cast<std::string>(this->_pos).length() != 0) {
        return false;
    } else if (this->_parsedValue > INT_MAX || this->_parsedValue < INT_MIN) {
        return false;
    }
    return true;
}

// bool Convertor::isFloat(std::string input) {}

// bool Convertor::isDouble(std::string input) {}

void Convertor::printChar(char c) {
    if (c > 127 && c < 32) {
        std::cout << "char : Non displayable" << std::endl;
    } else {
        std::cout << "char : '" << c << "'" << std::endl;
    }
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void Convertor::printInt(int n) {
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
    std::cout << "float : " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(n) << ".0" << std::endl;
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
    std::cout << "float : inff" << std::endl;
    std::cout << "double : inf" << std::endl;
}