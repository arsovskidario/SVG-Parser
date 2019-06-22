#pragma once
#include"Region.h"
class CircleRegion:public Region
{
private:
	double centerX, centerY, radius;
	public:
	CircleRegion(double centerX,double centerY,double radius)
	{
		this->centerX = centerX;
		this->centerY = centerY;
		this->radius = radius;
	}
	bool containsPoint(Point point) override
	{
		const double distanceFromCenterSquared =
			pow(point.x - centerX, 2) + pow(point.y - centerY, 2);
		return distanceFromCenterSquared <= pow(radius, 2);
	}
};