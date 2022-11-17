/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:15 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/17 17:40:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie originZombie("ORIGIN");
	originZombie.announce();

	Zombie *heapZombie = newZombie("HEAP");
	heapZombie->announce();

	delete heapZombie;

	randomChump("STACK");
	return 0;
}
