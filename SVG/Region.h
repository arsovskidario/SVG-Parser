#pragma once
#include"Point.h"
#include<cmath>
class Region
{
public:
	virtual bool containsPoint(Point point) = 0;
	virtual ~Region() = default;
};