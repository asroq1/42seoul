/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:08 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/14 17:47:39 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string cmd;
	int idx = 0;

	std::cout << "Program started ...." << std::endl;
	while (true)
	{
		std::cin >> cmd;
		if (cmd == "add")
		{
			phoneBook.add(cmd, idx);
			idx++;
		}
		else if (cmd == "search")
		{
			phoneBook.search();
		}
		else if (cmd == "exit")
		{
			phoneBook.exit(cmd);
			break;
		}
		else
		{
			std::cout << "wrong command" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		if (std::cin.eof())
		{
			break;
		}
	}
	return 0;
}