/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:49 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 13:27:26 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/12/05 18:51:30 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Scav Default constructor called" << std::endl;
	this->_name = "Default Scav";
	this->_hitPoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << name << "Scav constructor called" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor called" << std::endl;
}

<<<<<<< HEAD
void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enough energy points" << std::endl;
		return;
	}
	else if (this->_hitPoint == 0)
	{
		std::cout << "It doesn't work anymore" << std::endl;
		return;
	}
	--this->_energyPoints;
	std::cout << "Scav " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enough energy points" << std::endl;
=======
void ScavTrap::guardGate()
{
	std::cout << "guradGate is working..." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Scav Not enough energy points" << std::endl;
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
		return;
	}
	else if (this->_hitPoint == 0)
	{
<<<<<<< HEAD
		std::cout << "It doesn't work anymore" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "guradGate is working !" << std::endl;
	}
}
=======
		std::cout << "Scav It doesn't work anymore" << std::endl;
		return;
	}
	--this->_energyPoints;
	std::cout << "Scav : " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
}
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
