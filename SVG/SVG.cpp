#include "SVG.h"
#include"Circle.h"
#include"Ellipse.h"
#include"Rectangle.h"
#include<regex>
#include <iostream>

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
}

void SVG::translateShapes(double deltaX, double deltaY)
{
	for (Shape * shape : shapes)
		shape->translate(deltaX, deltaY);
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

void SVG::create(Shape* shape)
{
	shapes.push_back(shape);
}

void SVG::print()
{
	for (Shape * shape: shapes)
		shape->print();
}

void SVG::exit()
{
	std::cout << "Exiting the program ... \n";
	std::exit(EXIT_FAILURE);
}

