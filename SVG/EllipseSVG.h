#pragma once
#include"Shape.h"
class Ellipse:public Shape
{
	Ellipse();
	Ellipse(const Ellipse&);
	double RX;
	double RY;
	void setRX(double newRX);
	void setRY(double newRY);
public:
	Ellipse(double newCX, double newCY, double newRX, double newRY,
		std::string enteredFill, std::string enteredStroke, double enteredStrokeWidth);
	void translate(double transX, double transY) override;
	void print() override;
	double getRX()const;
	double getRY()const;
};