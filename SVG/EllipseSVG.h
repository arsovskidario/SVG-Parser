#pragma once
#include"BasicSVGShapes.h"
class EllipseSVG:public BasicSVGShapes
{
	EllipseSVG();
	EllipseSVG(const EllipseSVG&);
	double RX;
	double RY;
	void setRX(double newRX);
	void setRY(double newRY);
public:
	EllipseSVG(double newCX, double newCY, double newRX, double newRY,
		std::string enteredFill, std::string enteredStroke, double enteredStrokeWidth);
	void translate(double transX, double transY) override;
	void print() override;
	double getRX()const;
	double getRY()const;
};