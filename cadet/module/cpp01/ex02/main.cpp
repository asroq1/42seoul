/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:15 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/21 17:34:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR;
	stringPTR = &var;
	//	reference is similar pointer
	/*
	if you want to use ref. you have to initialize when you declare a variable
	and you can't change indicate other variable
	*/
	std::string &stringREF = var;
	std::cout << "----------------------------" << std::endl;
	std::cout << "var :" << &var << std::endl;
	std::cout << "stringPTR : " << &var << std::endl;
	std::cout << "stringREF : " << &var << std::endl;

	std::cout << "----------------------------" << std::endl;
	std::cout << "var : " << var << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	return 0;
}
