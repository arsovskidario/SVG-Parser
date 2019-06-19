#include "Rectangle.h"
#include "sstream"
#include <iostream>

void Rectangle::translate(double deltaX, double deltaY)
{
	this->x += deltaX;
	this->y += deltaY;
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
}


double Rectangle::getHeight() const
{
	return this->height;
}

double Rectangle::getWidth() const
{
	return this->width;
}
