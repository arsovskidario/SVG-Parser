#include"BasicSVGShapes.h"
//No one will use them
BasicSVGShapes::BasicSVGShapes()
{
}

BasicSVGShapes::BasicSVGShapes(const BasicSVGShapes&)
{
}

BasicSVGShapes::~BasicSVGShapes()
{
	fill.clear();
	stroke.clear();
}

void BasicSVGShapes::setX(double newX)
{
	this->x = newX;
}

void BasicSVGShapes::setY(double newY)
{
	this->y = newY;
}

double BasicSVGShapes::getX() const
{
	return this->x;
}

double BasicSVGShapes::getY() const
{
	return this->y;
}

void BasicSVGShapes::setFill(const std::string newFill)
{
	this->fill = newFill;
}

void BasicSVGShapes::setStroke(const std::string newStroke)
{
	this->stroke = newStroke;
}

void BasicSVGShapes::setStrokeWidth(double newStrokeWidth)
{
	this->strokeWidth = newStrokeWidth;
}

std::string BasicSVGShapes::getFill() const
{
	return this->fill;
}

std::string BasicSVGShapes::getStroke() const
{
	return this->stroke;
}

double BasicSVGShapes::getStrokeWidth() const
{
	return this->strokeWidth;
}

