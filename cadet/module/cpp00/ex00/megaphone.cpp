/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:19:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/10 17:20:01 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else{
		for (int i = 1; av[i] != 0; i++){
			for (int j = 0; av[i][j] != 0; j++){
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
	}
	return 0;
}