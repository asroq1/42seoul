/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:43:09 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/20 10:52:00 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimall";
	std::cout << "WrongAnimall Default Construct Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	this->type = ref.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destruct Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm " << this->type << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}