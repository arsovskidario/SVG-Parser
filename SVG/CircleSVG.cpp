#include"CircleSVG.h"

CircleSVG::CircleSVG():BasicSVGShapes()
{
}

CircleSVG::CircleSVG(const CircleSVG&):BasicSVGShapes()
{
}

void CircleSVG::setCR(double newCR)
{
	this->CR = newCR;
}

double CircleSVG::getCR() const
{
	return this->CR;
}

CircleSVG::CircleSVG(double newCX, double newCY, double newCR, std::string enteredFill, std::string enteredStroke,
	double enteredStrokeWidth):BasicSVGShapes()
{
	setX(newCX);
	setY(newCY);
	setCR(newCR);
	setFill(enteredFill);
	setStroke(enteredStroke);
	setStrokeWidth(enteredStrokeWidth);
}

CircleSVG::~CircleSVG()
{
}

void CircleSVG::translate(double transX, double transY)
{
	setX(getX()+transX);
	setY(getY() + transY);
}

void CircleSVG::print()
{
	std::cout << "circle" << " " << getX() << " " << getY() << " " << getCR() << " "<<getFill() 
			  <<" "<<getStroke()<<" "<<getStrokeWidth()<<std::endl;
}
