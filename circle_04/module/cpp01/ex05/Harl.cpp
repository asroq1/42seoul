/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:43:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 14:43:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->strArr[0] = "DEBUG";
	this->strArr[1] = "INFO";
	this->strArr[2] = "WARNING";
	this->strArr[3] = "ERROR";
	this->set_func[0] = &Harl::debug;
	this->set_func[1] = &Harl::info;
	this->set_func[2] = &Harl::warning;
	this->set_func[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->strArr[i])
		{
			(this->*set_func[i])();
		}
	}
}
