/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:43 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 15:31:51 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << this->type << " Default Construct Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	this->type = ref.getType();
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destruct Called" << std::endl;
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