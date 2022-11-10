/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:54:56 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/10 19:31:19 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>

class Contact
{
private:
	std::string number;
	std::string first;
	std::string last;
	std::string nick;
	std::string secret;
public:
	void	set_number(std::string number);
	void	set_first(std::string first);
	void	set_last(std::string last);
	void	set_nick(std::string nick);
	void	set_secrect(std::string secret);

};
#include <iostream>

class PhoneBook
{
private:
	int		i;
	Contact contacts[8];
public:
	void 	add(std::string input);
	void	search();
	int		exit();
};

#endif