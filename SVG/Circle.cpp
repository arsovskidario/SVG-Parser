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

bool Circle::checkWithIn(double centerX,double centerY, double radius)
{
	for (Point* edge : edges) //check for all points 
	{
		const double distanceFromCenterSquared =
			pow(edge->x - centerX, 2) + pow(edge->y - centerY, 2);
		return distanceFromCenterSquared <= pow(radius, 2);
	}
	return false;
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

double Circle::withIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	double radius = endHeight;
	double centerX = startWidth;
	double centerY = startHeight;
	double numberOfMatches = 0;
	if (checkWithIn(centerX,centerY, radius))
	{
		print();
		numberOfMatches++;
	}
	return numberOfMatches;
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
