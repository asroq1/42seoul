/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:00:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/01 11:54:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _bit = 8;

public:
	Fixed();
	Fixed(int _value);
	Fixed(const float _value);
	~Fixed();
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	Fixed &operator<<(const Fixed &obj);
	bool operator>(const Fixed &obj);
	bool operator<(const Fixed &obj);
	bool operator>=(const Fixed &obj);
	bool operator<=(const Fixed &obj);
	bool operator==(const Fixed &obj);
	bool operator!=(const Fixed &obj);
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);
	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int val);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed min(Fixed &obj1, Fixed &obj2);
	static Fixed min(const Fixed &obj1, const Fixed &obj2);
	static Fixed max(Fixed &obj1, Fixed &obj2);
	static Fixed max(const Fixed &obj1, const Fixed &obj2);
};
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif