/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:15 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 15:13:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPtr = &var;
	std::string &stringRef = var;
	//	reference is similar pointer
	/*
	if you want to use ref. you have to initialize when you declare a variable
	and you can't change indicate other variable
	*/
	std::cout << "----------------------------" << std::endl;
	std::cout << "var :" << &var << std::endl;
	std::cout << "stringPtr : " << stringPtr << std::endl;
	std::cout << "stringRef : " << &var << std::endl;

	std::cout << "----------------------------" << std::endl;
	std::cout << "var : " << var << std::endl;
	std::cout << "stringPtr : " << *stringPtr << std::endl;
	std::cout << "stringRef : " << stringRef << std::endl;
	return 0;
}
