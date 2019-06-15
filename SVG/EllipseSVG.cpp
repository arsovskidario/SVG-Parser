#include"EllipseSVG.h"

EllipseSVG::EllipseSVG():BasicSVGShapes()
{
}

EllipseSVG::EllipseSVG(const EllipseSVG&):BasicSVGShapes()
{
}

void EllipseSVG::setRX(double newRX)
{
	this->RX = newRX;
}

void EllipseSVG::setRY(double newRY)
{
	this->RY = newRY;
}

EllipseSVG::EllipseSVG(double newCX, double newCY,double newRX,double newRY,
					   std::string enteredFill, std::string enteredStroke,double enteredStrokeWidth):BasicSVGShapes()
{
	setX(newCX);
	setY(newCY);
	setRX(newRX);
	setRY(newRY);
	setFill(enteredFill);
	setStroke(enteredStroke);
	setStrokeWidth(enteredStrokeWidth);

}

double EllipseSVG::getRX() const
{
	return this->RX;
}

double EllipseSVG::getRY() const
{
	return this->RY;
}

void EllipseSVG::translate(double transX, double transY)
{
	setX(getX() + transX);
	setY(getY() + transY);
}
