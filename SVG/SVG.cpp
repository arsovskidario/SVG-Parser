#include "SVG.h"
#include"Circle.h"
#include"Ellipse.h"
#include"Rectangle.h"
#include<regex>
#include <iostream>
#include<fstream>
#include<ostream>
#include "CircleRegion.h"
#include "RectangleRegion.h"

SVG::~SVG()
{
  for (Shape* shape : shapes)
  {
	  delete shape;
  }

  shapes.clear();
}

SVG::SVG(std::vector<Shape*> shapes)
{
	this->shapes = shapes;
}

void SVG::translateCircle(double deltaX, double deltaY)
{
	for(auto circle:shapes)
	{
		Circle *castToCircle = dynamic_cast<Circle*>(circle);
		if(castToCircle!=nullptr)
		{
			circle->translate(deltaX, deltaY);
		}
	}
	std::cout << "Translated all circles \n";
}

void SVG::translateRectangle(double deltaX, double deltaY)
{
	for(auto rectangle:shapes)
	{
		Rectangle* castToRectange = dynamic_cast<Rectangle*>(rectangle);
		if(castToRectange!=nullptr)
		{
			rectangle->translate(deltaX, deltaY);
		}
	}
	std::cout << "Translated all rectangles \n";
}

void SVG::translateEllipse(double deltaX, double deltaY)
{
	for(auto ellipse: shapes)
	{
		Ellipse* castToEllipse = dynamic_cast<Ellipse*>(ellipse);
		if(castToEllipse!=nullptr)
		{
			ellipse->translate(deltaX, deltaY);
		}
	}
	std::cout << "Translated all ellipses \n";
}

void SVG::translateShapes(double deltaX, double deltaY)
{
	for (Shape * shape : shapes)
		shape->translate(deltaX, deltaY);
	std::cout << "Translated all figures \n";
}

void SVG::erase(int index)
{
	const int shapesCount = shapes.size();
	if (index < shapesCount)
	{
		shapes.erase(shapes.begin() + index);
		std::cout << "Successfully deleted element at position [" << index << "] \n";
	}
	else
		std::cout << "There is no figure number " << index << "! \n";
}

void SVG::create(Shape* shape,std::string identifier)
{
	std::cout << "Successfully created  " << identifier << "(" << shapes.size() << ") \n";
	shapes.push_back(shape);
}

void SVG::print()
{
	int indexEleemnt = 0;
	for (Shape * shape : shapes) {
		std::cout << indexEleemnt<<".";
		shape->print();
		indexEleemnt++;
	}
}


void SVG::createFile(std::ostream & outputFile, const std::vector<Shape*>& shapes)
{
    std::string xmlTag = "<?xml version=\"1.0\" standalone=\"no\"?> \n";
	std::string library = "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\" \n";
	std::string xmlSite = " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd \"> \n";
	std::string svgOpen = " <svg> \n";
	std::string svgClose = " </svg> \n";
	outputFile << xmlTag;
	outputFile << library;
	outputFile << xmlSite;
	outputFile << svgOpen;
	for (Shape * shape : shapes)
		outputFile << shape->toXml() << std::endl;
	outputFile << svgClose;
}

void SVG::save(std::string path, std::ifstream& inputFile,bool saveType)
{
	if(saveType) //distinguishes save and save as
		inputFile.open(path, std::ofstream::out | std::ofstream::trunc); //clears file with trunc

	std::ofstream outputFile(path);
	
	createFile(outputFile, shapes);
	std::cout << "Successfully saved the changes \n";
}

bool SVG::within(Region* region)
{
	bool matchesFound = false;
	for(Shape* shape:shapes)
	{
		bool isInRegion = true;
		std::vector<Point*> points = shape->getPoints();
		for(Point* point:points)
		{
			if(!region->containsPoint(*point))
			{
				isInRegion = false;
				break;
			}
		}
		if(isInRegion)
		{
			shape->print();
			matchesFound = true;
		}
	}
	return matchesFound;
}

void SVG::withinCircle(double centerX, double centerY, double radius)
{
	CircleRegion* circleRegion=new CircleRegion(centerX, centerY, radius);
	if (!within(circleRegion))
		std::cout << "No figures found in this Circle region ! \n";
}

void SVG::withinRectangle(double x, double y, double width, double height)
{
	RectangleRegion * rectangleRegion = new RectangleRegion(x, y, width, height);
	if (!within(rectangleRegion))
		std::cout << "No figures found in this Rectangle region ! \n";
}


void SVG::exit()
{
	std::cout << "Exiting the program ... \n";
	std::exit(EXIT_FAILURE);
}

