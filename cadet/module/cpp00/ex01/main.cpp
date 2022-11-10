#include "PhoneBook.hpp"

// cin 공부해서 다중입력 확인하기
int main()
{
	PhoneBook	phoneBook;
	std::string cmd;

	std::cout << "Program started ...." << std::endl;
	while (true)
	{
		std::cin >> cmd;
		if (cmd == "add")
		{
			phoneBook.add(cmd);
		}
		else if(cmd == "search")
		{

		}
		else if(cmd == "exit")
		{

		}
	}
	return 0;
} 