/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:20:51 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/13 13:49:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
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
	// 정확히 0이 아니면 최댓값 되버림 ??
	if (this->_hitPoint == 0 || this->_hitPoint < amount)
	{
		std::cout << "It already died" << std::endl;
		_hitPoint = 0;
		return;
	}
	this->_hitPoint -= amount;
	std::cout << "You got dameged " << amount << " Points!  Now your HP : " << this->_hitPoint << std::endl;
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
	std::cout << "You repaired " << amount << " Now your HP : " << this->_hitPoint << std::endl;
}