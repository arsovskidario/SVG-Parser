#include"CommandParser.h"
#include<cstring>
#include "CircleSVG.h"

void CommandParser::setPathAddress(const std::string newPathAddress)
{
	this->pathAddress = newPathAddress;
}

void CommandParser::parseFile()
{
	if(inFile.is_open())
	{
		std::string line;
		while(std::getline(inFile,line))
		{
			checkFigure(line);
		}
	}
}

void CommandParser::checkFigure(std::string fileLine)
{
	std::regex regCircle("^<circle.*>$");
	std::regex regRectangle("^<rect.*>$");
	std::regex regEllipse("^<ellipse.*>$");
	std::smatch match;
	if(std::regex_search(fileLine,match,regCircle))
		createCircle(fileLine);
	if (std::regex_search(fileLine, match, regRectangle) )
		createRectangle(fileLine);
	if (std::regex_search(fileLine, match, regEllipse) )
		createEllipse(fileLine);
}

void CommandParser::createCircle(std::string fileLine)
{
	// vector that stores all elements ;
	double parsedX=-1;
	double parsedY=-1;
	double parsedCR=-1;
	double parsedStrokeWidth=-1;
	std::string parsedFill="none"; // shows that user didn't enter anything
	std::string parsedStroke="none";
	std::regex regX(R"(<circle[^>]*cx\s*=\s*\"?(\d+)\"?[^>]*>)");
	std::regex regY(R"(<circle[^>]*cy\s*=\s*\"?(\d+)\"?[^>]*>)");
	std::regex regCR(R"(<circle[^>]*[(r)(cr)]\s*=\s*\"?(\d+)\"?[^>]*>)");
	std::regex regStrokeWidth(R"(<circle[^>]*stroke-width\s*=\s*\"?(\d+)\"?[^>]*>)");
	std::regex regFill(R"(<circle[^>]*fill\s*=\s*\"?(\w+)\"?[^>]*>)");
	std::regex regStroke(R"(<circle[^>]*stroke\s*=\s*\"?(\w+)\"?[^>]*>)");
}

void CommandParser::createRectangle(std::string fileLine)
{
}

void CommandParser::createEllipse(std::string fileLine)
{
}

std::string CommandParser::getPathAddress() const
{
	return this->pathAddress;
}

void CommandParser::open(const std::string address)
{
	inFile.open(address);

	if(!inFile.fail())
	{
		throw std::runtime_error("Invalid path! \n");
	}
	else
	{
		setPathAddress(address);
		std::cout << "Successfully opened the file ! \n";
		parseFile();
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

void CommandParser::translate(const std::string figureName)
{
}
