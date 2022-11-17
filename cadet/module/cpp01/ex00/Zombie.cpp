/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:02 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/17 17:35:22 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}
void Zombie::announce(void)
{
	std::cout << this->name << " : "
			  << "BraiiiiiiinnnzzzZ..." << std::endl;
}