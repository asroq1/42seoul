/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:08 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/16 14:23:19 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string cmd;
	int idx = 0;
	while (true)
	{
		std::cout << "There are three options [ADD, SEARCH, EXIT]" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			phoneBook.add(idx);
			idx++;
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.search();
		}
		else if (cmd == "EXIT")
		{
			phoneBook.exit();
			break;
		}
		else
		{
			std::cout << "ONLY USE [ADD, SEARCH, EXIT]" << std::endl;
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