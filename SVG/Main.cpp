#include<iostream>
#include "UserInterface.h"
#include <string>
void listCommands();
int main()
{
	listCommands();
	UserInterface userObject;
	std::string userInput;
	std::cin >> userInput;
	while(userObject.exit())
	{
		if(userInput.rfind("open",0)==0)
		{
			std::string addressInput = userInput.substr(userInput.find_first_of(" \t") + 1);
			userObject.open(addressInput);
		}
		else if(userInput.rfind("close",0)==0){
			userObject.close();
		}
		else if(userInput.rfind("save as ",0)==0)
		{
			userObject.saveAs();
		}
		else if (userInput.rfind("save",0)==0)
		{
			userObject.save();
		}
		else if(userInput.rfind("exit",0==0))
		{
			userObject.exit();
		}
	}
	//create an Object
}

void listCommands()
{
	std::cout << "These are the commands available to you :\n";
	std::cout << " open \n close \n save \n save as\n help\n";
}