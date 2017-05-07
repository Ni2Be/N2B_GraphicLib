#include "NB_Error_Log.h"
#include <fstream>
#include <string>
#include <iostream>


NB::NB_Error_Log::~NB_Error_Log()
{
	std::ofstream file("error.log");
	if (!file)
	{
		std::cerr << "\nNot able to save Error Log\n";
		for (auto& i : log_vec)
			std::cerr << i;
	}
	else
	{
		for (auto& i : log_vec)
		{
			file << i << std::endl;
		}
	}
}


void NB::NB_Error_Log::log(NB_Error signature, const std::string location, const std::string error)
{
	log_vec.push_back(Error(signature, location, error));
}