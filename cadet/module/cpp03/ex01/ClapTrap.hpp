/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:20:17 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 14:57:54 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/12/05 19:15:31 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void getHp(void);
};

#endif