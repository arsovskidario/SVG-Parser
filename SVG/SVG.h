#pragma once
#include<string>
#include<map>
#include<vector>
#include"Shape.h"
#include "Region.h"

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
	void create(Shape* shape,std::string identifier);
	void print();
	void createFile( std::ostream & outputFile, const std::vector<Shape*>& shapes);
	void save(std::string path, std::ifstream& inputFile,bool saveType);
	bool within(Region* region);
	void withinCircle(double centerX, double centerY, double radius);
	void withinRectangle(double x, double y, double width, double height);
	//void withIn(double startHeight, double endHeight,
		//        double startWidth, double endWidth);
	static void exit();
	SVG() = default;
	~SVG();
};

