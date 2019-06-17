#include"CommandParser.h"
#include<cstring>
#include "CircleSVG.h"

void CommandParser::setPath(const std::string &path)
{
	this->path = path;
}

void CommandParser::parseFileContent()
{
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			createShape(line);
		}
	}
}

std::map<std::string, std::string> CommandParser::parseAttributes(std::string text)
{
	std::map<std::string, std::string> attributes;

	std::regex attributesRegex(R"(([\w\-_]+)(?:=\"([^\"]*)\")?)");

	auto attributesBegin = std::sregex_iterator(text.begin(), text.end(), attributesRegex);
	auto attributesEnd = std::sregex_iterator();

	for (std::sregex_iterator attribute = attributesBegin; attribute != attributesEnd; ++attribute)
	{
		std::string attributeName = attribute->str(1);
		std::string attributeValue = attribute->str(2);
		attributes[attributeName] = attributeValue;
	}

	return attributes;
}

void CommandParser::createShape(std::string tag)
{
	std::regex shapeRegex(R"(<(circle|rect|ellipse)(.*)\/?>)");
	auto tagsBegin = std::sregex_iterator(tag.begin(), tag.end(), shapeRegex);
	auto tagsEnd = std::sregex_iterator();

	for (std::sregex_iterator tag = tagsBegin; tag != tagsEnd; ++tag)
	{
		std::string identifier = tag->str(1);
		std::string attributesText = tag->str(2);
		std::map<std::string, std::string> attributes = parseAttributes(attributesText);

		if (identifier == "circle")
		{
			createCircle(attributes);
		}
		else if (identifier == "rect")
		{
			createRectangle(attributes);
		}
		else if (identifier == "ellipse")
		{
			createEllipse(attributes);
		}
	}
}

bool CommandParser::try_get_attribute_value(
	const std::map<std::string, std::string>& attributes,
	const std::string& name,
	std::string& out)
{
	const auto iterator = attributes.find(name);

	if (iterator != attributes.end())
	{
		out = iterator->second;
		return true;
	}

	return false;
}

void CommandParser::createCircle(const std::map<std::string, std::string>& attributes)
{
	// set default values for unset attributes
	double center_x = 0;
	double center_y = 0;
	double radius = 0;
	std::string fill;
	std::string stroke;

	std::string current_value;

	if (try_get_attribute_value(attributes, "cx", current_value))
	{
		center_x = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "cy", current_value))
	{
		center_y = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "r", current_value))
	{
		radius = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}

	std::cout << "circle" << " " << center_x << " " << center_y << " " << radius << std::endl;
}

void CommandParser::createRectangle(const std::map<std::string, std::string>& attributes)
{
	// set default values for unset attributes
	double x = 0;
	double y = 0;
	double width = 0;
	double height = 0;

	std::string fill;
	std::string stroke;

	std::string current_value;

	if (try_get_attribute_value(attributes, "x", current_value))
	{
		x = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "y", current_value))
	{
		y = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "width", current_value))
	{
		width = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "height", current_value))
	{
		height = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}

	std::cout << "rectangle" << " " << x << " " << y << " " << width << " " << height << std::endl;
}

void CommandParser::createEllipse(const std::map<std::string, std::string>& attributes)
{
	// TODO: implement
}

std::string CommandParser::getPath() const
{
	return this->path;
}

void CommandParser::open(const std::string& path)
{
	inputFile.open(path);

	if (inputFile.fail())
	{
		throw std::runtime_error("Invalid path! \n");
	}

	setPath(path);
	std::cout << "Successfully opened the file ! \n";
	parseFileContent();
}

void CommandParser::close()
{
	if (inputFile.is_open())
	{
		inputFile.close();
		std::cout << "Successfully closed file! \n";
	}
	else
		std::cerr << "You didn't open a file ! \n";
}

void CommandParser::save()
{
	if (inputFile.is_open())
	{
		//need to store stuff into a file first 
		std::ofstream saveFile(getPath()); //save file to same directory
		std::cout << "Successfully saved another file \n";
	}
	else
	{
		std::cout << "You didn't open a file ! \n";
	}
}

void CommandParser::saveAs()
{
	if (inputFile.is_open())
	{
		std::string inputPath;
		std::cout << "Enter the path you wish to save your file : \n";
		std::getline(std::cin, inputPath);
		std::ofstream saveFile(inputPath);
		if (saveFile.fail())
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

void CommandParser::translate(const std::string& shapeName)
{
}
