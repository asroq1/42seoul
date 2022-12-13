/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:20:51 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 15:27:13 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/12/02 14:29:35 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
<<<<<<< HEAD
	std::cout << "Clap Default constructor called" << std::endl;
=======
	std::cout << "Default constructor called" << std::endl;
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	this->_name = "Default";
	this->_hitPoint = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " constructor called" << std::endl;
	this->_name = name;
	this->_hitPoint = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = obj._name;
	this->_hitPoint = obj._hitPoint;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "Copy assignment operator called " << std::endl;
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
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
	std::cout << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
<<<<<<< HEAD
	// 정확히 0이 아니면 최댓값 되버림 ??
=======
	//정확히 0이 아니면 최댓값 되버림 ??
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	if (this->_hitPoint == 0 || this->_hitPoint < amount)
	{
		std::cout << "It already died" << std::endl;
		_hitPoint = 0;
		return;
	}
	this->_hitPoint -= amount;
<<<<<<< HEAD
	std::cout << "You got dameged " << amount << " Points!  Now your HP : " << this->_hitPoint << std::endl;
=======
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "Not enough energy points" << std::endl;
		return;
	}
	else if (this->_hitPoint == 0)
	{
		std::cout << "Don't have HP" << std::endl;
		return;
	}
	this->_hitPoint += amount;
	--this->_energyPoints;
<<<<<<< HEAD
	std::cout << "You repaired " << amount << " Now your HP : " << this->_hitPoint << std::endl;
=======
}

void ClapTrap::getHp(void)
{
	std::cout << this->_hitPoint << std::endl;
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
}