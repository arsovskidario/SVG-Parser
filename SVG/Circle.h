#pragma once
#include"Shape.h"
#include "Point.h"

class Circle :public Shape
{
private:
	double centerX;
	double centerY;
	double radius;
	std::string fill;
	std::string stroke;
	std::vector<Point*> edges;
public:
	Circle(double center_x, double center_y, double radius,
		std::string fill, std::string stroke);
	double getRadius()const;

	void translate(double deltaX, double deltaY) override;
	void createEdges();
	std::vector<Point*> getPoints() const override;
	void print() override;
	std::string toXml() override;
};
