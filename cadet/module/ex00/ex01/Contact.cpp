#include "main.hpp"

class Contact
{
private:
	std::string number;
	std::string first;
	std::string last;
	std::string nick;
	std::string secret;
public:
	Contact(/* args */);
	~Contact();
	void	set_number(std::string number)
	{
		this->number = number;
	}
	void	set_first(std::string first)
	{
		this->first = first;
	}
	void	set_last(std::string last)
	{
		this->last = last;
	}
	void	set_nick(std::string nick)
	{
		this->nick = nick;
	}
	void	set_secrect(std::string secret)
	{
		this->secret = secret;
	}
};
