#include "NB_Utility.h"

#include <iostream>
#include <fstream>

void error_log(const std::string location, const std::string error)
{
	std::cerr << std::endl << "In " << location << std::endl << error << std::endl;
}


std::string load_file_to_string(const std::string& fileName)
{
	std::ifstream file((fileName).c_str());

	if (!file || !file.is_open())
		error_log(__func__, "Unable to load File: " + fileName);

	std::string output((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	std::string str(output);
	return str;
}