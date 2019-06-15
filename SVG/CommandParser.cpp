#include"CommandParser.h"
#include<cstring>

void CommandParser::setPathAddress(const std::string newPathAddress)
{
	this->pathAddress = newPathAddress;
}

std::string CommandParser::getPathAddress() const
{
	return this->pathAddress;
}

void CommandParser::open(const std::string address)
{
	inFile.open(address);

	//fileInput.open(address);
	if(!inFile.fail())
	{
		throw std::runtime_error("Invalid path! \n");
	}
	else
	{
		setPathAddress(address);
		std::cout << "Successfully opened the file ! \n";
	}
	/*if (fileInput.fail()){
		std::cerr << "Invalid path ! \n";
	}
	else {
		setPathAddress(address);
		std::cout << "Successfully opened the file ! \n";
	}
	inFile.open("address");*/
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
	if (inFile.is_open())
	{
		//need to store stuff into a file first 
		std::ofstream saveFile(getPathAddress()); //save file to same directory
		std::cout << "Successfully saved another file \n";
	}
	else
	{
		std::cout << "You didn't open a file ! \n";
	}
}

void CommandParser::saveAs()
{
	if(inFile.is_open())
	{
		std::string inputPath;
		std::cout << "Enter the path you wish to save your file : \n";
		std::getline(std::cin, inputPath);
		std::ofstream saveFile(inputPath);
		  if(saveFile.fail())
		  {
			  std::cerr << "You entered a invalid path! \n";
		  }
		  else 
		  {
			  std::cout << "Successfully saved another file \n";
		  }

	}
	else
	{
		std::cout << "You didn't open a file ! \n";
	}
 }

void CommandParser::exit()
{
	std::cout << "Exiting the program ... \n";
	std::exit(EXIT_FAILURE);
}
