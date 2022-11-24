/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:43:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 14:38:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string strArr[4];
	void (Harl::*set_func[4])();

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif