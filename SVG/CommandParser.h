#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<regex>
#include<vector>
#include<stdio.h>
#include <stdlib.h>  
class CommandParser
{
private:
	std::string pathAddress;
	std::ofstream userFile;
	std::ifstream  inFile;
	void setPathAddress(const std::string newPathAddress);
public:
	std::string getPathAddress()const;
	void open(const std::string address);
	void close();
	void save();
	void saveAs();
	void exit();
};