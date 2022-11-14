/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/14 17:48:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string number;
	std::string first;
	std::string last;
	std::string nick;
	std::string secret;
public:
	void		setNumber(std::string number);
	void		setFirst(std::string first);
	void		setLast(std::string last);
	void		setNick(std::string nick);
	void		setSecrect(std::string secret);
	
	std::string	getNumber();
	std::string	getFirst();
	std::string	getLast();
	std::string	getNick();
	std::string	getSecrect();

};
#include <iostream>

class PhoneBook
{
private:
	Contact contacts[8];
public:
	void 	add(std::string input, int idx);
	void	search();
	int		exit(std::string input);
};

#endif