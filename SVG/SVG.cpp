#include "SVG.h"
#include"Circle.h"
#include"Ellipse.h"
#include"Rectangle.h"
#include<regex>
#include <iostream>
#include<fstream>
#include<ostream>

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

void SVG::withIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	double  numberOfMatches = 0;
	for(Shape* shape:shapes)
	{
		numberOfMatches+=shape->withIn(startHeight,  endHeight, startWidth,  endWidth);
	}
	if (numberOfMatches == 0) std::cout << "No figures are located within the figure ! \n";
}

void SVG::exit()
{
	std::cout << "Exiting the program ... \n";
	std::exit(EXIT_FAILURE);
}

