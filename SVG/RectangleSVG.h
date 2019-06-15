#pragma once
#include"BasicSVGShapes.h"
class Rectangle:public BasicSVGShapes
{
	Rectangle();
	Rectangle(const Rectangle&);
	void setWidth(double newWidth);
	void setHeight(double newHeight);
	double width;
	double height;
public:
	Rectangle(double enteredX, double enteredY, double enteredWidth, double enteredHeight,
			   std::string enteredFill,std::string enteredStroke,double enteredStrokeWidth);
	~Rectangle();
	void translate(double transX, double transY) override;
	double getHeight()const;
	double getWidth()const;
};