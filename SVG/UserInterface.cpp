#include"UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::readCommand(std::string command)
{
	if (command==getOpen()) {//open
		std::string addressInput = command.substr(command.find_first_of(" \t") + 1);
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
