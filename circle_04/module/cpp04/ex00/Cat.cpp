/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat::Cat()
{
	this->type = "Cat";
	std::cout << this->type << " Default Construct Called" << std::endl;
}

Cat::Cat(const Cat &ref)
{
	this->type = ref.getType();
}

Cat::~Cat()
{
	std::cout << "Cat Destruct Called" << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "I'm " << this->type << " miaooo miaooo" << std::endl;
}
