/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:15:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/17 13:00:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];

public:
	std::string validate_cmd(std::string cmd);
	void add(int idx);
	void search();
	void exit();
};
