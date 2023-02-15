/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:44:24 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 14:40:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
int main(int ac, char *av[])
{
	Harl harl;

	if (ac == 2)
	{
		harl.complain(av[1]);
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	return 0;
}
