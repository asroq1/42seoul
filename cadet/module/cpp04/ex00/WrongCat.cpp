/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 13:41:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref)
{
	this->type = ref.getType();
}

WrongCat::~WrongCat()
{
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "I'm " << this->type << " mmm... mm.... doesn't work well" << std::endl;
}