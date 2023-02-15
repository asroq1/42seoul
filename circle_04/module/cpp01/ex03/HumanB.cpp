/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:55 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 17:47:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	this->name = "";
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << "1" << std::endl;
	std::cout << this->weapon->getType() << std::endl;
	if (this->weapon->getType().empty())
	{
		std::cout << "2" << std::endl;

		std::cout << "not exist weapon" << std::endl;
	}
	else
	{
		std::cout << "3" << std::endl;

		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}