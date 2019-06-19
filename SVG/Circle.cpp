#include"Circle.h"
#include "sstream"
#include <iostream>

Circle::Circle(double center_x, double center_y, double radius, std::string fill, std::string stroke) :Shape()
{
	this->centerX = center_x;
	this->centerY = center_y;
	this->radius = radius;
	this->fill = fill;
	this->stroke = stroke;
}

void Circle::translate(double deltaX, double deltaY)
{
	this->centerX += deltaX;
	this->centerY += deltaY;
}

void Circle::print()
{
	std::cout << "circle" << " " << centerX << " " << centerY << " " << radius << " "
		<< fill << " " << stroke << std::endl;
}

std::string Circle::toXml()
{
	std::ostringstream xml_stream;

	xml_stream << "<circle cx=\" " << centerX << "\"cy=\" " << centerY <<
		"\"r=\" " << radius <<
		"\" fill=\" " << fill << "\" stroke=\" " << stroke;

	return xml_stream.str();
}
