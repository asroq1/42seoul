/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:38 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/20 10:46:34 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Default Construct Called" << std::endl;
}

Dog::Dog(const Dog &ref)
{
	this->type = ref.getType();
	this->_brain = new Brain();
	std::cout << "Dog Copy assignment Called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destruct Called" << std::endl;
}

Dog &Dog::operator=(const Dog &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
		*(this->_brain) = *(ref._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "I'm " << this->type << " Wal--- Wall-- !" << std::endl;
}

std::string Dog::getIdeas(int q) const
{
	return this->_brain->_ideas[q];
}

void Dog::setIdeas(int q, std::string str)
{
	for (int i = 0; i < q; i++)
	{
		this->_brain->_ideas[q] = str;
	}
}