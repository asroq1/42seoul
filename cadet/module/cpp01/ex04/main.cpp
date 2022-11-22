/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:26:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/11/22 18:38:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "ac error" << std::endl;
		return 1;
	}
	std::string filePath = argv[1];
	std::ofstream outFile(filePath + ".replace");
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	int startIdx = 0;

	std::ifstream file;
	std::string readStr;
	if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL)
	{
		std::cout << "path error" << std::endl;
		return 0;
	}
	file.open(filePath);
	if (file.fail() || outFile.fail())
	{
		std::cout << "open error" << std::endl;
	}
	if (file.is_open())
	{
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
	}
	file.close();
	outFile.close();
	return 0;
}
