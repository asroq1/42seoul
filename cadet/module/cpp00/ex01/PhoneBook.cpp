#include "PhoneBook.hpp"

void PhoneBook::add(std::string input)
{
	std::cout << "Input your first name below ..." << std::endl;
	std::cin >> input;
	this->contacts[i].set_first(input);
	std::cout << "Input your last name below ..." << std::endl;
	std::cin >> input;
	this->contacts[i].set_last(input);
	std::cout << "Input your nickname below ..." << std::endl;
	std::cin >> input;
	this->contacts[i].set_nick(input);
	std::cout << "Input your phone number below ..." << std::endl;
	std::cin >> input;
	this->contacts[i].set_number(input);
	std::cout << "Input your darkest secret below ..." << std::endl;
	std::cin >> input;
	this->contacts[i].set_secrect(input);
};
void PhoneBook::search(){
	std::cout << "search" << std::endl;
};

int PhoneBook::exit(){
	std::cout << "Program finished ..." << std::endl;
	return 0;
};
