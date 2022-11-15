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
