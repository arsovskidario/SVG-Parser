#include"UserInterface.h"
#include "Ellipse.h"
#include <iostream>

UserInterface::~UserInterface()
{
	delete svg;
}

//check the read for the address
std::vector<std::string> UserInterface::getCommandParams(std::string command)
{
	std::stringstream stream(command);
	std::vector<std::string> params;
	while (!stream.eof())
	{
		std::string param;
		stream >> param;
		params.push_back(param);
	}

	return params;
}

void UserInterface::translateCircle(const std::map<std::string, std::string>& map)
{
	double deltaX = 0;
	double deltaY = 0;
	std::string current_value;

	if (try_get_attribute_value(map, "horizontal", current_value))
	{
		deltaX= std::stod(current_value);
	}

	if (try_get_attribute_value(map, "vertical", current_value))
	{
		deltaY = std::stod(current_value);
	}
	svg->translateCircle(deltaX, deltaY);
}

void UserInterface::translateRectangle(const std::map<std::string, std::string>& map)
{
	double deltaX = 0;
	double deltaY = 0;
	std::string current_value;

	if (try_get_attribute_value(map, "horizontal", current_value))
	{
		deltaX = std::stod(current_value);
	}

	if (try_get_attribute_value(map, "vertical", current_value))
	{
		deltaY = std::stod(current_value);
	}
	svg->translateRectangle(deltaX, deltaY);
}

void UserInterface::translateEllipse(const std::map<std::string, std::string>& map)
{
	double deltaX = 0;
	double deltaY = 0;
	std::string current_value;

	if (try_get_attribute_value(map, "horizontal", current_value))
	{
		deltaX = std::stod(current_value);
	}

	if (try_get_attribute_value(map, "vertical", current_value))
	{
		deltaY = std::stod(current_value);
	}
	svg->translateEllipse(deltaX, deltaY);
}

void UserInterface::translateShapes(const std::map<std::string, std::string>& map)
{
	double deltaX = 0;
	double deltaY = 0;
	std::string current_value;

	if (try_get_attribute_value(map, "horizontal", current_value))
	{
		deltaX = std::stod(current_value);
	}

	if (try_get_attribute_value(map, "vertical", current_value))
	{
		deltaY = std::stod(current_value);
	}
	svg->translateShapes(deltaX, deltaY);
}

void UserInterface::translate(const std::vector<std::string>& text)
{
	 const std::string identifier = text[0];
	 std::stringstream textStream;
	 std::vector < std::string> textPassed=text;
	std::map<std::string, std::string> attributes;
	if(identifier=="circle")
	{
		std::string parsedText = shapeStream(textStream, textPassed);
		attributes = parseTranslation(parsedText);
		translateCircle(attributes);
	}
	else if(identifier=="rectangle")
	{
		std::string parsedText = shapeStream(textStream, textPassed);
		attributes = parseTranslation(textStream.str());
		translateRectangle(attributes);
	}
	else if(identifier=="ellipse")
	{
		std::string parsedText = shapeStream(textStream, textPassed);
		attributes = parseTranslation(textStream.str());
		translateEllipse(attributes);
	}
	else
	{
		for (int i = 0; i < textPassed.size(); i++) 
		{
			textStream << textPassed[i];
		}
		attributes = parseTranslation(textStream.str());
		translateShapes(attributes);
	}
}

void UserInterface::executeCommand(std::vector<std::string> params)
{
	const std::string commandName = params[0];

	if (commandName == COMMANDS.OPEN)
	{
		const std::string path = params[1];
		open(path);
	}
	else if (commandName == COMMANDS.CLOSE)
	{
		if (isFileOpen()) {
			close();
		}
		else
		{
			std::cout << noOpenFileMessage << std::endl;
		}
	}
	else if (commandName == COMMANDS.SAVE)
	{
		if (isFileOpen()) {
			save();
		}
		else
		{
			std::cout << noOpenFileMessage << std::endl;
		}
	}
	else if (commandName == COMMANDS.SAVE_AS)
	{
		if (isFileOpen()) {
			const std::string path = params[1];
			saveAs(path);
		}
		else
		{
			std::cout << noOpenFileMessage << std::endl;
		}
	}
	else if (commandName == COMMANDS.PRINT)
	{
		if (isFileOpen()) {
			print();
		}
		else
		{
			std::cout << noOpenFileMessage << std::endl;
		}
	}
	else if(commandName==COMMANDS.EXIT)
	{
		exit();
	}
	else if(commandName==COMMANDS.ERASE)
	{
	   if(isFileOpen()){
		const int index = std::stoi(params[1]);
		erase(index);
	   }
	   else std::cout << noOpenFileMessage << std::endl;
	}
	else if (commandName==COMMANDS.TRANSLATE)
	{
		if(isFileOpen())
		{
			params.erase(params.begin());
			translate(params);
		}
		else std::cout << noOpenFileMessage << std::endl;
	}
	else
	{
		std::cout << "Invalid command.";
	}

}

void UserInterface::commandLoop()
{
	while (true)
	{
		std::string input;
		std::getline(std::cin, input);
		const std::vector<std::string> commandParams = getCommandParams(input);

		executeCommand(commandParams);
	}
}

bool UserInterface::isFileOpen()
{
	return this->svg != nullptr;
}

void UserInterface::start()
{
	commandLoop();
}

std::map<std::string, std::string> UserInterface::parseAttributes(std::string text)
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

std::string UserInterface::getFileContent()
{
	std::stringstream content;
	if (inputFile.is_open())
	{
		std::string line;
		while (!inputFile.eof())
		{
			std::getline(inputFile, line);
			content << line;
		}
	}

	return content.str();
}

void UserInterface::setPath(const std::string &path)
{
	this->path = path;
}

void UserInterface::open(const std::string& path)
{
	inputFile.open(path);
	std::string str;
	inputFile >> str;

	if (inputFile.fail())
	{
		throw std::runtime_error("Invalid path! \n");
	}

	setPath(path);
	std::cout << "Successfully opened the file ! \n";
	std::string content = getFileContent();
	std::vector<Shape*> shapes = parseShapes(content);
	this->svg = new SVG(shapes);
}

void UserInterface::close()
{

	if (inputFile.is_open())
	{
		inputFile.close();
		std::cout << "Successfully closed file! \n";
	}
	else
		std::cerr << "You didn't open a file ! \n";
}

void UserInterface::save()
{
	//TODO create a function that converts all the vector elements to text exampe:
	// <rect xy"(insert xy) ,then add it to a open file line 
	//you can delete the whole file and then replace all the text with the objects
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

void UserInterface::saveAs(std::string path)
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

void UserInterface::exit()
{
	svg->exit();
}

void UserInterface::erase(const int index)
{
	svg->erase(index);
}

std::map<std::string, std::string> UserInterface::parseTranslation(const std::string text)
{
	std::map<std::string, std::string> attributes;

	std::regex attributesRegex(R"((\w+)=(\d+))");

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

std::string UserInterface::shapeStream(std::stringstream& textStream, std::vector<std::string>& textPassed)
{
	for (int i = 1; i < textPassed.size(); i++) //skips the shape name
	{
		textStream << textPassed[i];
	}
	return textStream.str();
}

void UserInterface::print()
{
	svg->print();
}

std::string UserInterface::getPath() const
{
	return this->path;
}

Shape* UserInterface::createShape(std::sregex_iterator tag_iterator)
{
	std::string identifier = tag_iterator->str(1);
	std::string attributesText = tag_iterator->str(2);
	std::map<std::string, std::string> attributes = parseAttributes(attributesText);

	if (identifier == "circle")
	{
		return createCircle(attributes);
	}

	if (identifier == "rect")
	{
		return createRectangle(attributes);
	}

	if (identifier == "ellipse")
	{
		return createEllipse(attributes);
	}

	throw std::runtime_error("Shape " + identifier + " is not supported.");
}

bool UserInterface::try_get_attribute_value(
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

Circle* UserInterface::createCircle(const std::map<std::string, std::string>& attributes)
{
	// set default values for unset attributes
	double center_x = 0;
	double center_y = 0;
	double radius = 0;
	double strokeWidth = 0;
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

	if (try_get_attribute_value(attributes, "stroke-width", current_value))
	{
		strokeWidth = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}

	Circle* circle = new Circle(center_x, center_y, radius, stroke, fill);
	return circle;
}

Rectangle* UserInterface::createRectangle(const std::map<std::string, std::string>& attributes)
{
	// set default values for unset attributes
	double x = 0;
	double y = 0;
	double width = 0;
	double height = 0;
	double strokeWidth = 0;

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

	if (try_get_attribute_value(attributes, "stroke-width", current_value))
	{
		strokeWidth = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}

	Rectangle* rectangle = new Rectangle(x, y, width, height, fill, stroke);
	return rectangle;
}

Ellipse* UserInterface::createEllipse(const std::map<std::string, std::string>& attributes)
{
	double center_x = 0;
	double center_y = 0;
	double radius_x = 0;
	double radius_y = 0;
	double strokeWidth = 0;

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

	if (try_get_attribute_value(attributes, "rx", current_value))
	{
		radius_x = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "ry", current_value))
	{
		radius_y = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "stroke-width", current_value))
	{
		strokeWidth = std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}

	Ellipse* ellipse = new Ellipse(center_x, center_y, radius_x, radius_y, fill, stroke);
	return ellipse;
}

std::vector<Shape*> UserInterface::parseShapes(std::string text)
{
	std::vector<Shape*> shapes;

	std::regex shapeRegex(R"(<(circle|rect|ellipse)([^<]*)\/?>)");
	auto tagsBegin = std::sregex_iterator(text.begin(), text.end(), shapeRegex);
	auto tagsEnd = std::sregex_iterator();

	for (std::sregex_iterator tag_iterator = tagsBegin; tag_iterator != tagsEnd; ++tag_iterator)
	{
		try {
			Shape* shape = createShape(tag_iterator);
			shapes.push_back(shape);
		}
		catch (std::runtime_error &error)
		{
			std::cout << error.what();
		}
	}

	return shapes;
}
