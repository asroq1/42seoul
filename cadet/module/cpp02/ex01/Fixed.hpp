/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:00:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/28 19:49:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _base = 8;

public:
	Fixed();
	Fixed(int _value);
	Fixed(const float _value);
	~Fixed();
	// 	◦ A copy constructor.
	Fixed(const Fixed &obj);
	// ◦ A copy assignment operator overload.~Fixed();
	Fixed &operator=(const Fixed &obj);
	Fixed &operator<<(const Fixed &obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

#endif