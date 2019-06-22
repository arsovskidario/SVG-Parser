#pragma once
#include"Region.h"
class EllipseRegion :public Region
{
private:
	double centerX, centerY, radiusX, radiusY;
public:
	EllipseRegion(double centerX,double centerY,double radiusX,double radiusY)
	{
		this->centerX = centerX;
		this->centerY = centerY;
		this->radiusX = radiusX;
		this->radiusY = radiusY;
	}
	bool containsPoint(Point point) override
	{
		const double distanceFromCenterX = pow(point.x - centerX, 2) / pow(radiusX, 2);
		const double distanceFromCenterY = pow(point.y - centerY, 2) / pow(radiusY, 2);
		double distanceFromCrenter = distanceFromCenterX + distanceFromCenterY;
		return (distanceFromCenterX <= 1);
	}
};