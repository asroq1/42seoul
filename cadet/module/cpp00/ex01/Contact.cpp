/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/15 14:15:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setNumber(std::string number)
{
	this->number = number;
}
void Contact::setFirst(std::string first)
{
	this->first = first;
}
void Contact::setLast(std::string last)
{
	this->last = last;
}
void Contact::setNick(std::string nick)
{
	this->nick = nick;
}
void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

std::string Contact::getNumber()
{
	return this->number;
}

std::string Contact::getFirst()
{
	return this->first;
}
std::string Contact::getLast()
{
	return this->last;
}
std::string Contact::getNick()
{
	return this->nick;
}
std::string Contact::getSecret()
{
	return this->secret;
}