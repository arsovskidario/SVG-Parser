#include"Ellipse.h"
#include <sstream>
#include <iostream>
#include<cmath>
void Ellipse::setRadiusX(double radiusX)
{
	this->radiusX = radiusX;
}

void Ellipse::setRadiusY(double radiusY)
{
	this->radiusY = radiusY;
}

std::string Ellipse::toXml()
{
	std::ostringstream xml_stream;
	xml_stream << "<ellipse cx=\" " << centerX << "\"cy=\" " << centerY <<
		"\"rx=\" " << radiusX << "\"ry=\" " << radiusY <<
		"\" fill=\" " << fill << "\" stroke=\" " << stroke<< " />";

	return xml_stream.str();
}

Ellipse::Ellipse(double centerX, double centerY,
	double radiusX, double radiusY,
	std::string fill, std::string stroke)
{
	this->radiusX = radiusX;
	this->radiusY = radiusY;
	this->centerX = centerX;
	this->centerY = centerY;
	this->fill = fill;
	this->stroke = stroke;
	createEdges();
}

void Ellipse::createEdges()
{
	Point *A = new Point(this->centerX + getRadiusX(), this->centerY);
	edges.push_back(A);
	Point *B = new Point(this->centerX - getRadiusX(), this->centerY);
	edges.push_back(B);
	Point *C = new Point(this->centerX, this->centerY + getRadiusY());
	edges.push_back(C);
	Point *D = new Point(this->centerX, this->centerY - getRadiusY());
	edges.push_back(D);
}


double Ellipse::getRadiusX() const
{
	return this->radiusX;
}

double Ellipse::getRadiusY() const
{
	return this->radiusY;
}

void Ellipse::translate(double deltaX, double deltaY)
{
	this->centerX += deltaX;
	this->centerY += deltaY;
}


std::vector<Point*> Ellipse::getPoints() const
{
	return edges;
}

void Ellipse::print()
{
	std::cout << "ellipse" << " " << centerX << " " << centerY << " " <<
		radiusX << " " << radiusY << " " <<
		fill << " " << stroke << std::endl;
}
