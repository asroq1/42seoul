/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:33:51 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 17:51:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << this->type << " Default Construct Called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	this->type = ref.getType();
	std::cout << "Copy assignment Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destruct Called" << std::endl;
}

Animal &Animal::operator=(const Animal &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "I'm " << this->type << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}