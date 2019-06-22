#include"UserInterface.h"
#include "Ellipse.h"
#include <iostream>
#include<sstream>

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
		std::string parsedText = normalStream(textStream, textPassed);
		attributes = parseTranslation(textStream.str());
		translateShapes(attributes);
	}
}

void UserInterface::withIn(const std::vector<std::string>& text)
{
	const std::string identifier = text[0];
	std::vector<std::string> shortText = text;
	shortText.erase(shortText.begin());
	const int TEXT_SIZE = shortText.size();
	if(identifier=="rectangle")
	{
		const int RECTANGLE_SIZE = 4; //max attributes entered
		if(TEXT_SIZE==RECTANGLE_SIZE)
		{
			double startWidth = std::stod(shortText[0]);
			double startHeight = std::stod(shortText[1]);
			double endWidth = std::stod(shortText[2]);
			double endHeight = std::stod(shortText[3]);
			svg->withIn(startHeight, endHeight, startWidth, endWidth);
		}else std::cerr << "Enter a valid within format! \n";
	}
	else if(identifier=="circle")
	{
		const int CIRCLE_SIZE = 3;
		if(TEXT_SIZE==CIRCLE_SIZE)
		{
			double startWidth = std::stod(shortText[0]);
			double startHeight = std::stod(shortText[1]);
			double endWidth = std::stod(shortText[2]); // this is the radius of the circle 
			double endHeight = std::stod(shortText[2]);// this is the radius of the circle 
			svg->withIn(startHeight, endHeight, startWidth, endWidth);
		}else std::cerr << "Enter a valid within format! \n";
	}
	else if(identifier=="ellipse")
	{
		const int ELLIPSE_SIZE = 4;
		if(TEXT_SIZE==ELLIPSE_SIZE)
		{
			double startWidth = std::stod(shortText[0]);
			double startHeight = std::stod(shortText[1]);
			double endWidth = std::stod(shortText[2]);
			double endHeight = std::stod(shortText[3]);
			svg->withIn(startHeight, endHeight, startWidth, endWidth);
		}
		else std::cerr << "Enter a valid within format! \n";
	}
	else
		 std::cerr << "Enter a shape ! \n";
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
	else if (commandName == COMMANDS.EXIT)
	{
		exit();
	}
	else if (commandName == COMMANDS.ERASE) 
	{
		if (isFileOpen()) 
		{
			if (params.size() == 2 && !params[1].empty())
			{
			  std::string value = params[1];
				if (isdigit(value[0]))
				{
					const int index = std::stoi(value);
					if (index >= 0)
						erase(index);
					else std::cout << "No elements at that position ! \n";
				}
				else std::cout << "Enter a valid integer ! \n";
			}
			else std::cout << "Index needed ! \n";
		

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
	else if(commandName==COMMANDS.CREATE)
	{
		if(isFileOpen())
		{
			params.erase(params.begin());
			create(params);
		}
		else std::cout << noOpenFileMessage << std::endl;
	}
	else if(commandName==COMMANDS.WITH_IN)
	{
		if(isFileOpen())
		{
			params.erase(params.begin());
			withIn(params);
		}
		else std::cout << noOpenFileMessage << std::endl;
	}
	else
	{
		std::cout << "Invalid command. \n";
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
		svg = nullptr;
		std::cout << "Successfully closed file! \n";
	}
	else
		std::cerr << "You didn't open a file ! \n";
}

void UserInterface::save()
{
	bool save = true;
	if (inputFile.is_open())
	{
		svg->save(getPath(),inputFile,save);
	}
	else
	{
		std::cout << "You didn't open a file ! \n";
	}
}

void UserInterface::saveAs(std::string path)
{
	bool save = false;
	if (inputFile.is_open())
	{
		svg->save(path, inputFile,save);
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

void UserInterface::create(std::vector<std::string>& text)
{
	const std::string identifier = text[0];
	text.erase(text.begin()); //erases identifier
	const int TEXT_SIZE = text.size();
	if(identifier=="circle")
	{
		const int CIRCLE_ATTRIBUTES = 5; //max number of attributes
	   if(TEXT_SIZE==CIRCLE_ATTRIBUTES)
		svg->create(newCircle(text),identifier);
	   else std::cerr << "Enter a valid create format! \n";
	}
	else if(identifier=="rectangle")
	{
		const int RECTANGLE_ATTRIBUTES = 6; //max number of attributes
		if(TEXT_SIZE==RECTANGLE_ATTRIBUTES)
		svg->create(newRectangle(text),identifier);
		else std::cerr << "Enter a valid create format! \n";
	}
	else if(identifier=="ellipse")
	{
	   const int ELLIPSE_ATTRIBUTES = 6; //max number of attributes
	   if(TEXT_SIZE==ELLIPSE_ATTRIBUTES)
		svg->create(newEllipse(text),identifier);
	   else std::cerr << "Enter a valid create format! \n";
	}
	else std::cerr << "Enter a shape ! \n";
}

void UserInterface::erase(const int index)
{
   if(inputFile.is_open())
   {
	   svg->erase(index);
   }
   else std::cerr << "You didn't open a file ! \n";
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

std::string UserInterface::shapeStream(std::stringstream& textStream, std::vector<std::string>& text)
{
	for (int i = 1; i < text.size(); i++) //skips the identifier name
	{
		textStream << text[i];
	}
	return textStream.str();
}

std::string UserInterface::normalStream(std::stringstream& textStream, std::vector<std::string>& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		textStream << text[i];
	}
	return textStream.str();
}

Circle* UserInterface::newCircle(std::vector<std::string> text)
{
		double center_x = std::stod(text[0]);
		double center_y = std::stod(text[1]);
		double radius = std::stod(text[2]);
		std::string fill;
		fill = text[3];
		std::string stroke;
		stroke = text[4];
		Circle* circle = new Circle(center_x, center_y, radius, fill, stroke);
		return circle;
}

Rectangle* UserInterface::newRectangle(std::vector<std::string> text)
{
		double x = std::stod(text[0]);
		double y = std::stod(text[1]);
		double width = std::stod(text[2]);
		double height = std::stod(text[3]);
		std::string fill;
		fill = text[4];
		std::string stroke;
		stroke = text[5];
		Rectangle* rectangle = new Rectangle(x, y, width, height, fill, stroke);
		return rectangle;
}


Ellipse* UserInterface::newEllipse(std::vector<std::string> text)
{

		double center_x = std::stod(text[0]);
		double center_y = std::stod(text[1]);
		double radius_x = std::stod(text[2]);
		double radius_y = std::stod(text[3]);
		std::string fill;
		fill = text[4];
		std::string stroke;
		stroke = text[5];
		Ellipse* ellipse = new Ellipse(center_x, center_y, radius_x, radius_y, fill, stroke);
		return ellipse;
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
