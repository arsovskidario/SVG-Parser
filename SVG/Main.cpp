#include<iostream>
#include <string>
#include "UserInterface.h"

void listCommands();

int main()
{
	listCommands();
	UserInterface engine;
	engine.start();
}
void listCommands()
{
	std::cout << "These are the commands available to you :\n";
	std::cout << " open \n close \n save \n saveAs\n exit\n";
}