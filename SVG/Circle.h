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
	std::vector<Point*> edges;
public:
	Circle(double center_x, double center_y, double radius,
		std::string fill, std::string stroke);
	double getRadius()const;
	bool checkWithIn(double centerX,double centerY, double radius);

	void translate(double deltaX, double deltaY) override;
	void createEdges();
	double withIn(double startHeight, double endHeight, double startWidth, double endWidth) override;
	void print() override;
	std::string toXml() override;
};
