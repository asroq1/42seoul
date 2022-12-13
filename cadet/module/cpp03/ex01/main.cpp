/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:46 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 14:57:06 by hyunjung         ###   ########.fr       */
=======
/*   Updated: 2022/12/05 19:15:41 by hyunjung         ###   ########.fr       */
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
<<<<<<< HEAD
	ClapTrap a("A ");
	ScavTrap b("B ");

	std::cout << std::endl;
=======
	ScavTrap sung("sung");
	sung.attack("jung");
>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(110);
	a.beRepaired(10);
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	// ClapTrap *a = new ScavTrap("B");

	// std::cout << std::endl;

	// a->attack("A");
	// a->takeDamage(20);
	// a->beRepaired(3);
	// std::cout << std::endl;

	// std::cout << std::endl;

	// std::cout << std::endl;

	// delete a;
	return 0;
}
