#pragma once
#include"Shape.h"
class Ellipse :public Shape
{
private:
	double centerX;
	double centerY;
	double radiusX;
	double radiusY;
	std::string fill;
	std::string stroke;

public:
	Ellipse(double centerX, double centerY, 
		double radiusX, double radiusY,
		std::string fill, std::string stroke);

	void translate(double deltaX, double deltaY) override;
	void print() override;
	double getRadiusX()const;
	double getRadiusY()const;
	void setRadiusX(double radiusX);
	void setRadiusY(double radiusY);
	std::string toXml() override;
};