#include"CommandParser.h"

void CommandParser::open(std::string address)
{
	std::regex	exp("^(?:[a-zA-Z]\:|\\\\[\w\.]+\\[\w.$]+)\\(?:[\w]+\\)*\w([\w.])+$");
	std::smatch matchPath;
	bool checkBool;
	checkBool=std::regex_search(address, exp);
	//Make variable that stores true or false of parse search
	if(!checkBool || address.length()==0)
	{
		std::cout << "You entered an incorrect path \n";
	}
	else
	{
		std::cout << "Successfully opened " << address << std::endl;
		inFile.open("address");												
	}
}

void CommandParser::close()
{
	if (inFile.is_open()) {
	inFile.close();
	std::cout << "Successfully closed file! \n";
	}
   else
	   std::cerr << "You didn't open a file ! \n";
}

void CommandParser::save()
{
	std::cout << "Successfully saved file ! \n";
	// need to add items than it saves 
}

void CommandParser::saveAs()
{
	//need to save to a given location 
	std::cout << "Successfully saved another file \n";
}

void CommandParser::exit()
{
	std::cout << "Exiting the program ... \n";
	std::exit(EXIT_FAILURE);
}
