#pragma once
#include"Shape.h"
class Circle :public Shape
{
private:
	double centerX;
	double centerY;
	double radius;
	std::string fill;
	std::string stroke;
public:
	Circle(double center_x, double center_y, double radius,
		std::string fill, std::string stroke);

	void translate(double deltaX, double deltaY) override;
	void print() override;
	std::string toXml() override;
};
