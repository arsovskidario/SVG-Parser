#pragma once
#include<string>
#include <vector>
#include "Point.h"

class Shape
{
protected:
	int id;
	Shape()
	{
		static int sId = 0;
		this->id = ++sId;
	}
public:
	virtual ~Shape() = default;
	virtual void print() = 0;
	virtual void translate(double deltaX, double deltaY) = 0;
	virtual std::string toXml() = 0;
	virtual	std::vector<Point*> getPoints() const = 0;
};
