/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cPP                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:49 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/02 15:32:05 by hyunjung         ###   ########.fr       */
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
	std::cout << name << " constructor called" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
 
ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor called" << std::endl;
}

 void ScavTrap::guardGate()
 {
	 std::cout << "guradGate is working..." << std::endl;
 }
