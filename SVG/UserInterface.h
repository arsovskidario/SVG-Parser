#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
class UserInterface
{
private:
	std::ofstream userFile;
public:
	void open(std::string address);
	void close();
	void save();
	void saveAs();
	bool exit()
	{
		return true;
	};
};