/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/21 18:44:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << "test attact" << this->weapon.getType() << std::endl;
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
