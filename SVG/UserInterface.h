#pragma once
#include<string>
#include "CommandParser.h"
#include<sstream>
#include "SVG.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Ellipse.h"

class UserInterface
{
	struct
	{
		const std::string OPEN = "open";
		const std::string CLOSE = "close";
		const std::string SAVE = "save";
		const std::string SAVE_AS = "saveAs";
		const std::string PRINT = "print";
		const std::string EXIT = "exit";
		const std::string ERASE = "erase";
		const std::string TRANSLATE = "translate";
		const std::string CREATE = "create";

	} COMMANDS;

	const std::string noOpenFileMessage = "No file was opened.";
private:
	std::string path;
	std::ofstream outputFile;
	std::ifstream inputFile;
	SVG* svg = nullptr;

	void setPath(const std::string &path);
	std::string getFileContent();
	static std::vector<std::string>getCommandParams(const std::string command);
	void translateCircle(const std::map<std::string, std::string>& map);
	void translateRectangle(const std::map<std::string, std::string>& map);
	void translateEllipse(const std::map<std::string, std::string>& map);
	void translateShapes(const std::map<std::string, std::string>& map);
	void executeCommand(std::vector<std::string> params);
	void commandLoop();
	bool isFileOpen();

	static bool try_get_attribute_value(const std::map<std::string, std::string>& attributes,
		const std::string& name, std::string& out);

	static Shape* createShape(std::sregex_iterator tag_iterator);
	static Circle* createCircle(const std::map<std::string, std::string>& attributes);
	static Rectangle* createRectangle(const std::map<std::string, std::string>& attributes);
	static Ellipse* createEllipse(const std::map<std::string, std::string>& attributes);

	static std::vector<Shape*> parseShapes(std::string text);
	static std::map<std::string, std::string> parseAttributes(std::string text);
	std::map<std::string, std::string> parseTranslation(const std::string text);
	std::string shapeStream(std::stringstream &textStream, std::vector<std::string> &textPassed);

	std::string getPath() const;
	void open(const std::string& path);
	void close();
	void save();
	void saveAs(std::string path);
	void print();
	void exit();
	void erase(int index);
	void translate(const std::vector<std::basic_string<char>>& cses);
public:
	UserInterface() = default;
	~UserInterface();

	void start();
};
