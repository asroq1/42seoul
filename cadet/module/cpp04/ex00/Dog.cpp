/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:15 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << this->type << " Default Construct Called" << std::endl;
}

Dog::Dog(const Dog &ref)
{
	this->type = ref.getType();
}

Dog::~Dog()
{
	std::cout << "Dog Destruct Called" << std::endl;
}

Dog &Dog::operator=(const Dog &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "I'm " << this->type << " Wal--- Wall-- !" << std::endl;
}
