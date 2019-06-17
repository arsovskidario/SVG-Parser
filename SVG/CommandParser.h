#pragma once
#include<vector>
#include "BasicSVGShapes.h"
#include "iostream"
#include<sstream>
#include <map>

class CommandParser
{
private:
	std::string path;
	std::ofstream outputFile;
	std::ifstream inputFile;
	std::vector<BasicSVGShapes> shapes; // need to open file and read it 
	void setPath(const std::string &path);
	void parseFileContent();
	static std::map<std::string, std::string> parseAttributes(std::string text);
	void createShape(std::string tag);
	static bool try_get_attribute_value(const std::map<std::string, std::string>& attributes,
	                                    const std::string& name, std::string& out);
	void createCircle(const std::map<std::string, std::string>& attributes);
	void createRectangle(const std::map<std::string, std::string>& attributes);
	void createEllipse(const std::map<std::string, std::string>& attributes);
public:
	std::string getPath() const;
	void open(const std::string& path);
	void close();
	void save();
	void saveAs();
	void exit();
	void translate(const std::string& shapeName);
	// use the vector of all shapes and search for given figure
	//if no figure entered translate all of the objects in the vector

	// or create two overloads named "translate":
	// (1) one - accepting arguments "id" and the offset
	// (2) and the other - accepting only the offset
	// check if an id of the shape is passed as a "translate" command argument
	// and call one of the overloads based on that
};
