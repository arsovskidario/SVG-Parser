#pragma once
#include"Shape.h"
class Rectangle :public Shape
{
	double x;
	double y;
	double width;
	double height;
	std::string fill;
	std::string stroke;
public:
	Rectangle(double x, double y, double width, double height,
		std::string fill, std::string stroke);

	double getHeight()const;
	double getWidth()const;
	void setWidth(double newWidth);
	void setHeight(double newHeight);

	void translate(double deltaX, double deltaY) override;
	void print() override;
	std::string toXml() override;
};