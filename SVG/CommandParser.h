#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>
#include<stdio.h>
#include <stdlib.h>  
class CommandParser
{
private:
	std::ofstream userFile;
	std::ifstream  inFile;
public:
	void open(std::string address);
	void close();
	void save();
	void saveAs();
	void exit();
};