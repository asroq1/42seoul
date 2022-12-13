/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:20:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/13 14:57:54 by hyunjung         ###   ########.fr       */
=======
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:20:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/04 17:30:17 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
<<<<<<< HEAD
protected:
=======
private:
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
<<<<<<< HEAD
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	virtual void attack(const std::string &target);
=======
	~ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	void attack(const std::string &target);
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void getHp(void);
};
<<<<<<< HEAD

=======
`
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
#endif