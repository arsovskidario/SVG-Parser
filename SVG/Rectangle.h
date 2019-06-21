#pragma once
#include"Shape.h"

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

	void translate(double deltaX, double deltaY) override;
	void createEdges();
	bool checkWithIn(double startHeight, double endHeight, double startWidth, double endWidth);
	void withIn(double startHeight, double endHeight, double startWidth, double endWidth)override;
	void print() override;
	std::string toXml() override;
};
