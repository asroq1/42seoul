/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:23:56 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:27 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newZombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		newZombie[i].setName(name);
	}
	return newZombie;
}