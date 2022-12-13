/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:46 by hyunjung          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/13 15:22:28 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A ");
	FragTrap b("B ");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(110);
	a.beRepaired(10);
	std::cout << std::endl;

	b.highFivesGuys();
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
=======
/*   Updated: 2022/12/02 14:58:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap korea("Korea");
	ClapTrap portugal("Portugal");

	korea.attack("Portugal");
	portugal.takeDamage(3);
	portugal.takeDamage(7);
	portugal.attack("Korea");
	portugal.beRepaired(7);

>>>>>>> e3f6eb98eedb67ea9e9aba103d97d83045846638
	return 0;
}
