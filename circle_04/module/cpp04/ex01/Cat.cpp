/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/20 10:58:08 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Default Construct Called" << std::endl;
}

Cat::Cat(const Cat &ref)
{
	this->_brain = new Brain(*ref._brain);
	*this = ref;
	std::cout << "Cat Copy Construct Called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destruct Called" << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
		*(this->_brain) = *(ref._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "I'm " << this->type << " miaooo miaooo" << std::endl;
}

std::string Cat::getIdeas(int q) const
{
	return this->_brain->_ideas[q];
}

void Cat::setIdeas(int q, std::string str)
{
	for (int i = 0; i < q; i++)
	{
		this->_brain->_ideas[q] = str;
	}
}