#include"Ellipse.h"

Ellipse::Ellipse():BasicSVGShapes()
{
}

Ellipse::Ellipse(const Ellipse&):BasicSVGShapes()
{
}

void Ellipse::setRX(double newRX)
{
	this->RX = newRX;
}

void Ellipse::setRY(double newRY)
{
	this->RY = newRY;
}

Ellipse::Ellipse(double newCX, double newCY,double newRX,double newRY,
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

double Ellipse::getRX() const
{
	return this->RX;
}

double Ellipse::getRY() const
{
	return this->RY;
}

void Ellipse::translate(double transX, double transY)
{
	setX(getX() + transX);
	setY(getY() + transY);
}

void Ellipse::print()
{
	std::cout << "ellipse" << " " << getX() << " " << getY() << " " << getRX() << " " << getRY() << " " << getFill()
		      << " " << getStroke() << " " << getStrokeWidth() << std::endl;
}
