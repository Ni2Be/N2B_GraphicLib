#include "NB_Utility.h"

#include <iostream>
#include <fstream>


//Set up the Error Log:
NB::NB_Error_Log<> NB_Err;
void NB::error_log(const std::string location, const std::string error)
{
	NB_Err.err_log(NB::NB_Error(NB::NB_ERROR, location, error));
	std::cerr << std::endl << "In " << location << std::endl << error << std::endl;
}

//Simple file loading
std::string NB::load_file_to_string(const std::string& fileName)
{
	std::ifstream file((fileName).c_str());

	if (!file || !file.is_open())
		error_log("NB::load_file_to_string", "Unable to load File: " + fileName);

	std::string output((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	std::string str(output);
	return str;
}
