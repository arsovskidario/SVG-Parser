#include<iostream>
#include <string>
#include "UserInterface.h"
#include "CommandParser.h"

void listCommands();

int main()
{
	listCommands();
	std::string userInput;
	UserInterface userObject;
	while(true)
	{
		std::getline(std::cin,userInput);
		userObject.readCommand(userInput);
	}
}
void listCommands()
{
	std::cout << "These are the commands available to you :\n";
	std::cout << " open \n close \n save \n saveAs\n exit\n";
	/*std::string path;
	std::cin >> path;
	CommandParser parser;
	parser.open(path);*/
}