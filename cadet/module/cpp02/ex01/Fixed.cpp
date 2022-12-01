/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:00:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/01 12:09:58 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int _value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = _value << this->_bit;
}

Fixed::Fixed(const float _value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(_value * (1 << this->_bit));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_value = obj.getRawBits();
	}
	return *this;
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