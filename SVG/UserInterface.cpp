#include"UserInterface.h"

void UserInterface::open(std::string address)
{
	if(address.length()==0)
	{
		std::cout << "You entered an incorrect path \n";
	}
	std::regex	exp("^(?:[a-zA-Z]\:|\\\\[\w\.]+\\[\w.$]+)\\(?:[\w]+\\)*\w([\w.])+$");
}
