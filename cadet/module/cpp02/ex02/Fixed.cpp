/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:00:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/30 21:31:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(int _value)
{
	this->_value = _value << this->_bit;
}

Fixed::Fixed(const float _value)
{
	this->_value = roundf(_value * (1 << this->_bit));
}

Fixed::Fixed(const Fixed &obj)
{
	this->_value = obj.getRawBits();
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_bit);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_bit;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
	{
		this->_value = obj.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &obj)
{
	return this->getRawBits() > obj.getRawBits() ? true : false;
}

bool Fixed::operator<(const Fixed &obj)
{
	return this->getRawBits() < obj.getRawBits() ? true : false;
}

bool Fixed::operator>=(const Fixed &obj)
{
	return this->getRawBits() >= obj.getRawBits() ? true : false;
}

bool Fixed::operator<=(const Fixed &obj)
{
	return this->getRawBits() <= obj.getRawBits() ? true : false;
}

bool Fixed::operator==(const Fixed &obj)
{
	return this->getRawBits() == obj.getRawBits() ? true : false;
}

bool Fixed::operator!=(const Fixed &obj)
{
	return this->getRawBits() != obj.getRawBits() ? true : false;
}

Fixed &Fixed::operator+(const Fixed &obj)
{
	Fixed tmp = this->toFloat() + obj.toFloat();
	return tmp;
}

Fixed &Fixed::operator-(const Fixed &obj)
{
	Fixed tmp = this->toFloat() - obj.toFloat();
	return tmp;
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed &Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed &Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed &Fixed::operator*(const Fixed &obj)
{
	Fixed tmp = this->toFloat() * obj.toFloat();
	return tmp;
}

Fixed &Fixed::operator/(const Fixed &obj)
{
	Fixed tmp = this->toFloat() / obj.toFloat();
	return tmp;
}

Fixed Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return obj1.toFloat() > obj2.toFloat() ? obj2.toFloat() : obj1.toFloat();
}

Fixed Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return obj1.toFloat() > obj2.toFloat() ? obj2.toFloat() : obj1.toFloat();
}

Fixed Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return obj1.toFloat() > obj2.toFloat() ? obj1.toFloat() : obj2.toFloat();
}

Fixed Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return obj1.toFloat() > obj2.toFloat() ? obj1.toFloat() : obj2.toFloat();
}