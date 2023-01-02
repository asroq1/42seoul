/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:40:10 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/02 14:56:57 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>

class Convertor {
  private:
    char *_value;
    char _charValue;
    int _intValue;
    // float _floatValue;
    // double _doubleValue;
    double _parsedValue;
    char *_pos;
    std::string _origin;

  public:
    Convertor();
    Convertor(const Convertor &ref);
    ~Convertor();

    Convertor &operator=(const Convertor &ref);
    void setValue(std::string input, char *av);
    bool isChar(std::string input);
    bool isInt();
    bool isFloat();
    bool isDouble();
    bool isNan();
    bool isInf();
    void printChar(char c);
    void printInt(int n);
    void printFloat();
    void printDouble();
    void printNan();
    void printInf(char *av);
};

#endif
