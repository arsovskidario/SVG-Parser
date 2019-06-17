#include"UserInterface.h"

UserInterface::UserInterface()
{
}
//check the read for the address
void UserInterface::readCommand(std::string command)
{
	if (command.empty())
		std::cout << "Enter a command please ! \n";
	if (command.substr(0, 5) == getOpen()) {//open
		std::vector<std::string> commandTokens;
		std::string buf; //Have a buffer 
		std::stringstream ss(command);//Insert the commands into a stream
		while(ss>>buf)
		{
			commandTokens.push_back(buf);
		}
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
