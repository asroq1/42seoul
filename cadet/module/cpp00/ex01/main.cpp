/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:08 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/15 15:57:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string cmd;
	int idx = 0;
	int i = 1;
	while (true)
	{
		std::cout << i << "i is" << std::endl;
		std::cout << "There are three options [ADD, SEARCH, EXIT]" << std::endl;
		if (cmd == "ADD")
		{
			phoneBook.add(idx);
			idx++;c
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