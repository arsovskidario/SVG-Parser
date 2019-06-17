#pragma once
#include"BasicSVGShapes.h"
class CircleSVG:public BasicSVGShapes
{
	CircleSVG();
	CircleSVG(const CircleSVG&);
	void setCR(double newCR);
	double CR; //radius coord
public:
		CircleSVG(double newCX, double newCY, double newCR,
			std::string enteredFill, std::string enteredStroke, double enteredStrokeWidth);
		~CircleSVG();
		void translate(double transX,double transY) override;
		void print() override;
		double getCR()const;
	
};
