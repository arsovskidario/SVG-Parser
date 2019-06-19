#include "Rectangle.h"

Rectangle::Rectangle():Shape()
{
}

Rectangle::Rectangle(const Rectangle&):Shape()
{

}


Rectangle::~Rectangle()
{
}

void Rectangle::translate(double deltaX, double deltaY)
{
	setX(getX()+deltaX);
	setY(getY()+deltaY);
}

void Rectangle::print()
{
	std::cout << "rectangle" << " " << getX() << " " << getY()<< " " << getWidth() << " " << getHeight() 
	          <<" "<<getFill()<<" "<<getStroke() << " " << getStrokeWidth() << std::endl;
}

void Rectangle::setWidth(double newWidth)
{
	this->width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
	this->height = newHeight;
}

Rectangle::Rectangle(double x, double y, double width, double height, std::string fill,
					  std::string stroke, double enteredStrokeWidth) :Shape()
{
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setFill(fill);
	setStroke(stroke);
	setStrokeWidth(enteredStrokeWidth);
}


double Rectangle::getHeight() const
{
	return this->height;
}

double Rectangle::getWidth() const
{
	return this->width;
}
