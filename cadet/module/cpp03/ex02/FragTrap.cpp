/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:17:25 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/13 15:44:48 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Frag Default constructor called" << std::endl;
	this->_name = "Default Frag";
	this->_hitPoint = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Frag constructor called" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enough energy points" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "Frag Trap high five guys!" << std::endl;
	}
}
=======
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:35:12 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/05 18:35:12 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
