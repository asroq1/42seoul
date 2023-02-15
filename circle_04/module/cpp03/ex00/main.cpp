/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:08:46 by hyunjung          #+#    #+#             */
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

	return 0;
}
