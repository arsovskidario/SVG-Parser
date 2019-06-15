#include"RectangleSVG.h"

Rectangle::Rectangle():BasicSVGShapes()
{
}

Rectangle::Rectangle(const Rectangle&):BasicSVGShapes()
{

}


Rectangle::~Rectangle()
{
}

void Rectangle::translate(double transX, double transY)
{
	setX(getX()+transX);
	setY(getY()+transY);
}

void Rectangle::setWidth(double newWidth)
{
	this->width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
	this->height = newHeight;
}

Rectangle::Rectangle(double enteredX, double enteredY, double enteredWidth, double enteredHeight, std::string enteredFill,
					  std::string enteredStroke, double enteredStrokeWidth) :BasicSVGShapes()
{
	setX(enteredX);
	setY(enteredY);
	setWidth(enteredWidth);
	setHeight(enteredHeight);
	setFill(enteredFill);
	setStroke(enteredStroke);
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
