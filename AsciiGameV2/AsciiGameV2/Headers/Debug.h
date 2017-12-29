#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Debug
{
public : 
	static void log(std::string filename, std::string text, bool append = false);
};