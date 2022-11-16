/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:33:10 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/16 14:33:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	void setNumber(std::string number);
	void setFirst(std::string first);
	void setLast(std::string last);
	void setNick(std::string nick);
	void setSecret(std::string secret);

	std::string getNumber();
	std::string getFirst();
	std::string getLast();
	std::string getNick();
	std::string getSecret();
};
