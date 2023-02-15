/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:26:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/24 14:56:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char const *av[])
{
	if (ac != 4)
	{
		std::cout << "argc error" << std::endl;
		return 1;
	}
	std::string filePath = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	int startIdx = 0;

	std::ifstream file;
	std::string readStr;
	if (av[1] == NULL || av[2] == NULL || av[3] == NULL)
	{
		std::cout << "path error" << std::endl;
		return 1;
	}
	file.open(filePath);
	if (file.fail())
	{
		std::cout << "open error" << std::endl;
		return 1;
	}
	std::ofstream outFile(filePath + ".replace");
	while (!file.eof())
	{
		startIdx = 0;
		getline(file, readStr);
		while (true)
		{
			startIdx = readStr.find(s1, startIdx);
			if (startIdx == std::string::npos)
			{
				break;
			}
			readStr.erase(startIdx, s1.length());
			readStr.insert(startIdx, s2);
			startIdx += s2.length();
		}
		outFile << readStr;
		outFile << std::endl;
	}
	file.close();
	outFile.close();
	return 0;
}
