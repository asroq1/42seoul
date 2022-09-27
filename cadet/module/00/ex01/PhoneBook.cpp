#include "main.hpp"

class PhoneBook
{
private:
	int i = 0;
	std::string input;
	Contact contacts[8];
public:
	PhoneBook(/* args */);
	~PhoneBook();

	void add()
	{
		std:std::cout << "Input your first name below ..." << std::endl;
		std::cin >> input;
		this->contacts[i].set_first(input);
		std:std::cout << "Input your last name below ..." << std::endl;
		std::cin >> input;
		this->contacts[i].set_last(input);
		std:std::cout << "Input your nickname below ..." << std::endl;
		std::cin >> input;
		this->contacts[i].set_nick(input);
		std:std::cout << "Input your phone number below ..." << std::endl;
		std::cin >> input;
		this->contacts[i].set_number(input);
		std:std::cout << "Input your darkest secret below ..." << std::endl;
		std::cin >> input;
		this->contacts[i].set_secrect(input);
	};
	void search();
	int	exit();
};
