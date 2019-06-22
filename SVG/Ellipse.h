#pragma once
#include"Shape.h"
#include "Point.h"

class Ellipse :public Shape
{
private:
	double centerX;
	double centerY;
	double radiusX;
	double radiusY;
	std::string fill;
	std::string stroke;
	std::vector<Point*>edges;

public:
	Ellipse(double centerX, double centerY, 
		double radiusX, double radiusY,
		std::string fill, std::string stroke);

	void createEdges();

	std::vector<Point*> getPoints()const override;
	void translate(double deltaX, double deltaY) override;
	void print() override;
	double getRadiusX()const;
	double getRadiusY()const;
	void setRadiusX(double radiusX);
	void setRadiusY(double radiusY);
	std::string toXml() override;
};
