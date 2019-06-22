#include"Circle.h"
#include "sstream"
#include <iostream>
#include<cmath>

Circle::Circle(double center_x, double center_y, double radius, std::string fill, std::string stroke) :Shape()
{
	this->centerX = center_x;
	this->centerY = center_y;
	this->radius = radius;
	this->fill = fill;
	this->stroke = stroke;
	createEdges();
}

double Circle::getRadius() const
{
	return this->radius;
}


void Circle::translate(double deltaX, double deltaY)
{
	this->centerX += deltaX;
	this->centerY += deltaY;
}

void Circle::createEdges()
{
	Point *A = new Point(this->centerX + getRadius(), this->centerY);
	edges.push_back(A);
	Point *B = new Point(this->centerX, this->centerY + getRadius());
	edges.push_back(B);
	Point *C = new Point(this->centerX - getRadius(), this->centerY);
	edges.push_back(C);
	Point *D = new Point(this->centerX, this->centerY - getRadius());
	edges.push_back(D);
}

std::vector<Point*> Circle::getPoints() const
{
	return edges;
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
		"\" fill=\" " << fill << "\" stroke=\" " << stroke<< " />";

	return xml_stream.str();
}
