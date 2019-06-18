#pragma once
#include<string>
#include "CommandParser.h"

class UserInterface
{
private:
	std::string close = "close";
	std::string open = "open ";
	std::string save = "save";
	std::string saveAs = "saveAs ";
	std::string exit = "exit";
	std::string translate = "translate ";
	std::string print = "print";
	std::string erase = "erase ";
	std::string create = "create ";
	CommandParser parserObject;
public:
	UserInterface();
	void readCommand(const std::string command);
	std::string getClose() const;
	std::string getOpen() const;
	std::string getSave() const;
	std::string getSaveAs() const; 
	std::string getExit() const;
	std::string getTranslate()const;
	std::string getPrint()const;
	std::string getErase()const;
	std::string getCreate()const;
};
