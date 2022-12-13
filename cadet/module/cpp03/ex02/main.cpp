/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:46 by hyunjung          #+#    #+#             */
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
	return 0;
}
