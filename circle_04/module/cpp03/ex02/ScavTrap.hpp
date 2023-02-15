/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:47 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 13:27:37 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/12/02 15:21:53 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

<<<<<<< HEAD
#include "ClapTrap.hpp"
=======
#include <iostream>
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
<<<<<<< HEAD
	void attack(const std::string &target);
=======
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	void guardGate();
};

#endif