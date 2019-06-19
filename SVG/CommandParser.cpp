#include"CommandParser.h"
#include "CircleSVG.h"
#include "RectangleSVG.h"
#include "EllipseSVG.h"
//Global inFile for opening closing files
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
	double strokeWidth=0;
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
		strokeWidth= std::stod(current_value);
	}

	if (try_get_attribute_value(attributes, "fill", current_value))
	{
		fill = current_value;
	}

	if (try_get_attribute_value(attributes, "stroke", current_value))
	{
		stroke = current_value;
	}
	shapes.emplace_back(new CircleSVG(center_x, center_y, radius, stroke, fill, strokeWidth));
}

void CommandParser::createRectangle(const std::map<std::string, std::string>& attributes)
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

	shapes.emplace_back(new Rectangle(x, y, width, height, fill, stroke, strokeWidth));
}

void CommandParser::createEllipse(const std::map<std::string, std::string>& attributes)
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

	shapes.emplace_back(new EllipseSVG(center_x, center_y, radius_x, radius_y, fill, stroke, strokeWidth));
}

bool CommandParser::createInputShape(const std::vector<std::string>& shapeInput)
{
	if(shapeInput[0]=="rectangle")
	{
		int rectMin = 8; //no of elements a rectangle needs to have 
		if (shapeInput.size() != rectMin) return false;
		std::string rectTag = "<rect x=\" " + shapeInput[1];
		std::string rectY = "\"y=\" " + shapeInput[2];
		std::string rectWidth = "\"width=\"" + shapeInput[3];
		std::string rectHeight = "\" height=\" " + shapeInput[4];
		std::string rectFill = "\" fill=\" " + shapeInput[5];
		std::string rectStroke = "\" stroke=\" " + shapeInput[6];
		std::string rectStrokeWidth = "\" stroke-width=\" " + shapeInput[7]+"\">";
		std::string rectShape = rectTag + rectY + rectWidth + rectHeight + rectFill + rectStroke + rectStrokeWidth;
		createShape(rectShape);
		return true;
	}

	if(shapeInput[0]=="circle")
	{
		int circleMin = 7;
		if (shapeInput.size() != circleMin) return false;
		std::string circleTag = "<circle cx=\" " + shapeInput[1];
		std::string circleCY= "\"cy=\" " + shapeInput[2];
		std::string circleR= "\"r=\" " + shapeInput[3];
		std::string circleFill = "\" fill=\" " + shapeInput[4];
		std::string circleStroke = "\" stroke=\" " + shapeInput[5];
		std::string circleStrokeWidth = "\" stroke-width=\" " + shapeInput[6] + "\">";
		std::string circleShape = circleTag + circleCY + circleR + circleFill + circleStroke + circleStrokeWidth;
		createShape(circleShape);
		return true;
	}

	if(shapeInput[0]=="ellipse")
	{
		int ellipseMin = 8;
		if (shapeInput.size() != ellipseMin) return false;
		std::string ellipseTag = "<ellipse cx=\" " + shapeInput[1];
		std::string ellipseCY = "\"cy=\" " + shapeInput[2];
		std::string ellipseRX = "\"rx=\" " + shapeInput[3];
		std::string ellipseRY = "\"ry=\" " + shapeInput[4];
		std::string ellipseFill = "\" fill=\" " + shapeInput[5];
		std::string ellipseStroke = "\" stroke=\" " + shapeInput[6];
		std::string ellipseStrokeWidth = "\" stroke-width=\" " + shapeInput[7] + "\">";
		std::string ellipseShape = ellipseTag + ellipseCY + ellipseRX + ellipseRY + ellipseFill + ellipseStroke + ellipseStrokeWidth;
		createShape(ellipseShape);
		return true;
	}
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
	else{
	setPath(path);
	std::cout << "Successfully opened the file ! \n";
	parseFileContent();
	}
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

void CommandParser::print()
{
	for(int i=0;i<shapes.size();i++)
	{
		shapes[i]->print();
	}
}

void CommandParser::erase(int index)
{
	if (index < shapes.size())
	{
		shapes.erase(shapes.begin() + index);
		std::cout << "Successfully deleted element at position [" << index << "] \n";
	}
	else
		std::cout << "There is no figure number " << index << "! \n";
}

void CommandParser::create(const std::vector<std::string>& shapeInput)
{
	if (!shapeInput.empty())
	{
		if (createInputShape(shapeInput))
			std::cout << "Successfully created shape at (" << shapes.size() - 1 << ") position.\n";
		else
			std::cerr << "Enter the correct shape format \n";
	}
}
