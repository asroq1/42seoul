/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:15 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 15:04:51 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie originZombie("First Stack");
	originZombie.announce();

	Zombie *heapZombie = newZombie("HEAP");
	heapZombie->announce();

	delete heapZombie;

	randomChump("Second Stack");
	return 0;
}
