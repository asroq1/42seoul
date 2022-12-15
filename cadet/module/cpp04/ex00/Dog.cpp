/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 13:08:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
}

Dog::Dog(const Dog &ref)
{
	this->type = ref.getType();
}

Dog::~Dog()
{
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
