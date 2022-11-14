/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/14 17:37:02 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add(std::string cmd, int idx)
{
	std::cout << idx << std::endl;
	if (idx >= 8)
	{
		idx = idx % 8;
	}
	std::cout << "Input your first name below ..." << std::endl;
	std::cin >> cmd;
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9);
		cmd += ".";
	}
	this->contacts[idx].setFirst(cmd);
	std::cout << "Input your last name below ..." << std::endl;
	std::cin >> cmd;
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9);
		cmd += ".";
	}
	this->contacts[idx].setLast(cmd);
	std::cout << "Input your nickname below ..." << std::endl;
	std::cin >> cmd;
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9);
		cmd += ".";
	}
	this->contacts[idx].setNick(cmd);
	std::cout << "Input your phone number below ..." << std::endl;
	std::cin >> cmd;
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9);
		cmd += ".";
	}
	this->contacts[idx].setNumber(cmd);
	std::cout << "Input your darkest secret below ..." << std::endl;
	std::cin >> cmd;
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9);
		cmd += ".";
	}
	this->contacts[idx].setSecrect(cmd);
	std::cout << "Saved information" << std::endl;
};

void PhoneBook::search()
{
	int idx;
	std::cout << std::setw(10) << "index"
			  << "|";
	std::cout << std::setw(10) << "first name"
			  << "|";
	std::cout << std::setw(10) << "last name"
			  << "|";
	std::cout << std::setw(10) << "nickname"
			  << "|";
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << this->contacts[i].getFirst() << "|";
		std::cout << std::setw(10) << this->contacts[i].getLast() << "|";
		std::cout << std::setw(10) << this->contacts[i].getNick() << "|";
		std::cout << std::endl;
	}
	std::cin >> idx;
	std::cout << "FirstName : " << this->contacts[idx - 1].getFirst() << std::endl;
	std::cout << "LastName : " << this->contacts[idx - 1].getLast() << std::endl;
	std::cout << "NickName : " << this->contacts[idx - 1].getNick() << std::endl;
	std::cout << "Secrect : " << this->contacts[idx - 1].getSecrect() << std::endl;
};

int PhoneBook::exit(std::string cmd)
{
	std::cout << "Program finished ..." << std::endl;
	std::cout << "cmd is" << cmd << std::endl;
	return 0;
};
