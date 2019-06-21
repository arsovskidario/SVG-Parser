#include"Ellipse.h"
#include <sstream>
#include <iostream>

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
		"\" fill=\" " << fill << "\" stroke=\" " << stroke;

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

bool Ellipse::checkWithIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	for (Point* edge : edges) //check for all points 
	{
		if ((edge->x > startWidth) && (edge->x < endWidth) && (edge->y > startHeight) && (edge->x < endHeight))
		{
			return true;
		}
	}
	return false;
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

void Ellipse::withIn(double startHeight, double endHeight, double startWidth, double endWidth)
{
	int numberOfMatches = 0;
	if (checkWithIn(startHeight, endHeight, startWidth, endWidth))
	{
		print();
	}
	if (numberOfMatches == 0) std::cout << "No figures are located within the figure ! \n";
}

void Ellipse::print()
{
	std::cout << "ellipse" << " " << centerX << " " << centerY << " " <<
		radiusX << " " << radiusY << " " <<
		fill << " " << stroke << std::endl;
}
