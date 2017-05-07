#include "NB_Error_Log.h"
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include <thread>

//CLASS ERROR
NB::Error::Error(NB_Error signature, const std::string location, const std::string error)
	:signature(signature), location(location), error_name(error)
{
	//set time
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	this->time_stamp = std::chrono::system_clock::to_time_t(now);
}

std::ostream& NB::operator<<(std::ostream& os, const Error& err)
{
	std::tm error_time;
	localtime_s(&error_time, &err.time_stamp);
	os << "At: " << std::put_time(&error_time, "%F %T") << std::endl
		<< "in: " << err.location << std::endl
		<< err.error_name << std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl;
	return os;
	
}

//CLASS ERROR_LOG
NB::NB_Error_Log::~NB_Error_Log()
{
	std::ofstream file;
	file.open("final_error.log", std::ios::app);
	if (!file)
	{
		std::cerr << "\nNot able to save Error Log:\n";
		for (auto& i : log_vec)
			std::cerr << *i << std::endl;
	}
	else
	{
		for (auto& i : log_vec)
		{
			file << *i << std::endl;
			delete i;
		}
	}
}

void NB::NB_Error_Log::print_errors()
{
	for (auto& i : log_vec)
		std::cout << *i << std::endl;
}

void NB::NB_Error_Log::save_error(const Error& err)
{
	std::ofstream file;
	file.open("error.log", std::ios::app);
	if (!file.is_open()) std::cerr << "\nCould not open error.log\n";
	file << err << std::endl;
}

void NB::NB_Error_Log::log(NB_Error signature, const std::string location, const std::string error)
{
	std::lock_guard<std::mutex> lk1(this->mutex);
	
	log_vec.push_back(new Error(signature, location, error));
	save_error(*log_vec.back());
}
