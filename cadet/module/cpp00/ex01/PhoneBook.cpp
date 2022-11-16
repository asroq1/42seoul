/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/16 14:28:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::validate_cmd(std::string cmd)
{
	if (cmd.length() > 10)
	{
		cmd = cmd.substr(0, 9).append(".");
	}
	return (cmd);
}

void PhoneBook::add(int idx)
{
	std::string	cmd;

	if (idx >= 8)
	{
		idx %= 8;
	}
	std::cout << "First Name" << std::endl;
	std::cin >> cmd;
	this->contacts[idx].setFirst(cmd);
	std::cout << "Last Name" << std::endl;
	std::cin >> cmd;
	this->contacts[idx].setLast(cmd);
	std::cout << "Nick Name" << std::endl;
	std::cin >> cmd;
	this->contacts[idx].setNick(cmd);
	std::cout << "Phone Number" << std::endl;
	std::cin >> cmd;
	this->contacts[idx].setNumber(cmd);
	std::cout << "Darkest Secret" << std::endl;
	std::cin >> cmd;
	this->contacts[idx].setSecret(cmd);
	std::cout << "Saved All Information" << std::endl;
}

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
		std::cout << std::setw(10) << validate_cmd(this->contacts[i].getFirst()) << "|";
		std::cout << std::setw(10) << validate_cmd(this->contacts[i].getLast()) << "|";
		std::cout << std::setw(10) << validate_cmd(this->contacts[i].getNick()) << "|";
		std::cout << std::endl;
	}
	std::cin >> idx;
	if (idx > 0 && idx < 9)
	{
		std::cout << "FirstName : " << this->contacts[idx - 1].getFirst() << std::endl;
		std::cout << "LastName : " << this->contacts[idx - 1].getLast() << std::endl;
		std::cout << "NickName : " << this->contacts[idx - 1].getNick() << std::endl;
		std::cout << "Number : " << this->contacts[idx - 1].getNumber() << std::endl;
		std::cout << "Secret : " << this->contacts[idx - 1].getSecret() << std::endl;	
	}
	else
	{
		std::cout << "Wrong Index" << std::endl;
	}
}

void PhoneBook::exit()
{
	std::cout << "Program Finished ..." << std::endl;
};
