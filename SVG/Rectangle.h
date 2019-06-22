#pragma once
#include"Shape.h"
#include "Point.h"

class Rectangle :public Shape
{
private:
	double x;
	double y;
	double width;
	double height;
	std::string fill;
	std::string stroke;
	std::vector<Point*> edges;
public:
	Rectangle(double x, double y, double width, double height,
		std::string fill, std::string stroke);
	~Rectangle();

	double getHeight()const;
	double getWidth()const;
	void setWidth(double newWidth);
	void setHeight(double newHeight);

	std::vector<Point*> getPoints() const override;
	void translate(double deltaX, double deltaY) override;
	void createEdges();
	void print() override;
	std::string toXml() override;
};
