#pragma once
#include<string>
#include <vector>
class Shape
{
protected:
	int id;
	struct Point
	{
		double x;
		double y;
		Point(double x,double y)
		{
			this->x = x;
			this->y = y;
		}
	};

	Shape()
	{
		static int sId = 0;
		this->id = ++sId;
	}
public:
	virtual ~Shape() = default;
	virtual void print() = 0;
	virtual void translate(double deltaX, double deltaY) = 0;
	virtual void withIn(double startHeight, double endHeight, double startWidth, double endWidth) = 0;
	virtual std::string toXml() = 0;
};