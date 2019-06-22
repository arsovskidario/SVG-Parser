#pragma once
#include"Region.h"
class RectangleRegion :public Region
{
private:
	double x, y, width, height;
public:
	RectangleRegion(double x,double y,double width,double height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	bool containsPoint(Point point) override
	{
		// checks if the point is in the rectangle area 
		if ((point.x > x) && (point.x < width) && (point.y > y) && (point.y < height))
			return true;
		else return false;
	}
};