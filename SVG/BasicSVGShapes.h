#pragma once
#include<string>
#include<iostream>
class BasicSVGShapes
{
    double x;
	double y;
	double strokeWidth;
	std::string fill;
	std::string stroke;
	BasicSVGShapes(const BasicSVGShapes&);
public:	
	~BasicSVGShapes();
	virtual void print() = 0;
	virtual void translate(double transX,double transY) = 0;
protected:
	BasicSVGShapes();
	void setX(double newX);
	void setY(double newY);
	void setStroke(const std::string newStroke);
	void setFill(const std::string newFill);
	void setStrokeWidth(const double newStrokeWidth);
	double getX()const;
	double getY()const;
	double getStrokeWidth() const;
	std::string getFill()const;
	std::string getStroke()const;

};