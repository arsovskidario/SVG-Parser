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
	std::vector<Point*>edges;

public:
	Ellipse(double centerX, double centerY, 
		double radiusX, double radiusY,
		std::string fill, std::string stroke);

	void createEdges();
	bool checkWithIn(double startHeight, double endHeight, double startWidth, double endWidth);
	double withIn(double startHeight, double endHeight, double startWidth, double endWidth)override;

	void translate(double deltaX, double deltaY) override;
	void print() override;
	double getRadiusX()const;
	double getRadiusY()const;
	void setRadiusX(double radiusX);
	void setRadiusY(double radiusY);
	std::string toXml() override;
};