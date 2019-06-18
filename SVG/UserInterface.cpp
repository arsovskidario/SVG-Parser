#include"UserInterface.h"

UserInterface::UserInterface()
{
}
//check the read for the address
void UserInterface::readCommand(std::string command)
{
	std::vector<std::string> commandTokens;
	std::string buf; //Have a buffer 
	std::stringstream ss(command);//Insert the commands into a stream

	while (ss >> buf)
	{
		commandTokens.push_back(buf);
	}
	if (command.empty())
		std::cout << "Enter a command please ! \n";

	if (command.substr(0, 5) == getOpen())
	{
		const std::string addressInput = commandTokens[1]; //skips open and gets address
		parserObject.open(addressInput);
	}

	if (command==getClose())
	{
		parserObject.close();
	}

	if (command==getSave())
	{
		parserObject.save();
	}

	if (command==getSaveAs())
	{
		parserObject.saveAs();
	}

	if (command==getExit())
	{
		parserObject.exit();
	}

	if(command==getPrint())
	{
		parserObject.print();
	}

	if(command.substr(0,6)==getErase())
	{
		int indexInput = std::stoi(commandTokens[1]);
		parserObject.erase(indexInput);
	}

	if (command.substr(0,7)==getCreate())
	{
		commandTokens.erase(commandTokens.begin());
		parserObject.create(commandTokens);
	}
}

std::string UserInterface::getClose() const
{
	return close;
}

std::string UserInterface::getOpen() const
{
	return open;
}

std::string UserInterface::getSave() const
{
	return save;
}

std::string UserInterface::getSaveAs() const
{
	return saveAs;
}

std::string UserInterface::getExit() const
{
	return exit;
}

std::string UserInterface::getTranslate() const
{
	return this->translate;
}

std::string UserInterface::getPrint() const
{
	return this->print;
}

std::string UserInterface::getErase() const
{
	return this->erase;
}

std::string UserInterface::getCreate() const
{
	return this->create;
}
