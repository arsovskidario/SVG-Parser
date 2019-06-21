#pragma once
#include<string>
#include<map>
#include<vector>
#include"Shape.h"
class SVG
{
private:
	std::vector<Shape*> shapes;
public:
	SVG(std::vector<Shape*> shapes);
	template<typename T>
	T* create()
	{
		Shape* shape = new T();
		shapes.push_back(shape);
		return shape;
	}

	void translateCircle(double deltaX, double deltaY);
	void translateRectangle(double deltaX, double deltaY);
	void translateEllipse(double deltaX, double deltaY);
	void translateShapes(double deltaX, double deltaY);
	void erase(int index);
	void create(Shape* shape);
	void print();
	void withIn(double startHeight, double endHeight,
		        double startWidth, double endWidth);
	static void exit();
	SVG() = default;
	~SVG();
};

