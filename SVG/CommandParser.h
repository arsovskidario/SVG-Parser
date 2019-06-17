#pragma once
#include<iostream>
#include<fstream>





































































































#include<string>
#include<sstream>
#include<regex>
#include<vector>
#include<stdio.h>
#include <stdlib.h>  
#include "BasicSVGShapes.h"

class CommandParser
{
private:
	std::string pathAddress;
	std::ofstream userFile;
	std::ifstream  inFile;
	std::vector<BasicSVGShapes> allFigures; // need to open file and read it 
	void setPathAddress(const std::string newPathAddress);
	void parseFile();
	void checkFigure(std::string fileLine);
	void createCircle(std::string fileLine);
	void createRectangle(std::string fileLine);
	void createEllipse(std::string fileLine);
public:
	std::string getPathAddress()const;
	void open(const std::string address);
	void close();
	void save();
	void saveAs();
	void exit();
	void translate(const std::string figureName); // use the vector of all shapes and search for given figure
	//if no figure entered translate all of the objects in the vector
};
