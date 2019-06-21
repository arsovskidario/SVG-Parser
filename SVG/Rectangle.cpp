#include "Rectangle.h"
#include "sstream"
#include <iostream>

void Rectangle::translate(double deltaX, double deltaY)
{
	this->x += deltaX;
	this->y += deltaY;
}

void Rectangle::createEdges()
{
	Point *A=new Point(this->x, this->y);
	edges.push_back(A);
	Point *B=new Point(this->x + getWidth(), this->y);
	edges.push_back(B);
	Point *C=new Point(this->x, this->y + getHeight());
	edges.push_back(C);
	Point *D=new Point(this->x + getWidth(), this->y + getHeight());
	edges.push_back(D);
}

bool Rectangle::checkWithIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	for (Point* edge : edges) //check for all points 
	{
		if((edge->x > startWidth) && (edge->x < endWidth) && (edge->y > startHeight) && (edge->x < endHeight))
		{
			return true;
		}
	}
	return false;
}

void Rectangle::withIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	if(checkWithIn(startHeight,endHeight,startWidth,endWidth))
	{
		print();
	}
}

void Rectangle::print()
{
	std::cout << "rectangle" << " " << x << " " << y << " " << width << " " << height
		<< " " << fill << " " << stroke << std::endl;
}

std::string Rectangle::toXml()
{
	std::ostringstream xml_stream;

	xml_stream << "<rect x=\" " << x << "\"y=\" " << y <<
		"\"width=\"" << width << "\" height=\" " << height
		<< "\" fill=\" " << fill << "\" stroke=\" " + stroke;

	return xml_stream.str();
}

void Rectangle::setWidth(double newWidth)
{
	this->width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
	this->height = newHeight;
}

Rectangle::Rectangle(double x, double y,
	double width, double height,
	std::string fill, std::string stroke)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->fill = fill;
	this->stroke = stroke;
	createEdges();
}

Rectangle::~Rectangle()
{
	for (Point* edge : edges)
	{
		delete edge;
	}
	edges.clear();
}


double Rectangle::getHeight() const
{
	return this->height;
}

double Rectangle::getWidth() const
{
	return this->width;
}
