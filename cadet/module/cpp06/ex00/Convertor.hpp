/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:40:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/30 12:14:22 by hyunjung         ###   ########.fr       */
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

  public:
    Convertor();
    Convertor(const Convertor &ref);
    ~Convertor();

    Convertor &operator=(const Convertor &ref);
    void setValue(std::string input, char *av);
    bool isChar(std::string input);
    bool isInt(std::string input);
    bool isFloat();
    bool isDouble();
    bool isNan();
    bool isInf();
    void printChar(char c);
    void printInt(int n);
    void printFloat();
    void printDouble();
    void printNan();
    void printInf();
};

#endif
