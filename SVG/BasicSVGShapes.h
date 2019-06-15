#pragma once
#include<string>
class BasicSVGShapes
{
    double x;
	double y;
	double strokeWidth;
	std::string fill;
	std::string stroke;
	BasicSVGShapes();
	BasicSVGShapes(const BasicSVGShapes&);
protected:
	~BasicSVGShapes();
	void setX(double newX);
	void setY(double newY);
	void setStroke(const std::string newStroke);
	void setFill(const std::string newFill);
	void setStrokeWidth(const double newStrokeWidth);
	virtual void translate(double transX,double transY) = 0;
	double getX()const;
	double getY()const;
	double getStrokeWidth() const;
	std::string getFill()const;
	std::string getStroke()const;

};