/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/15 13:15:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat::Cat()
{
	this->type = "Cat";
}

Cat::Cat(const Cat &ref)
{
	this->type = ref.getType();
}

Cat::~Cat()
{
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
