#include "NB_Error_Log.hpp"
#include <iostream>
#include <iomanip>
#include <string>

//CLASS ERROR
/*
Simple defaul error constructor that sets a time stamp
*/
NB::NB_Error::NB_Error(NB_Error_Flag signature, const std::string location, const std::string error)
	:signature(signature), location(location), error_name(error)
{
	//set time
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	this->time_stamp = std::chrono::system_clock::to_time_t(now);
}

/*
The output operator will print the log with seperation lines on it's bottom
*/
std::ostream& NB::operator<<(std::ostream& os, const NB_Error& err)
{
	std::tm error_time;
	localtime_s(&error_time, &err.time_stamp);
	os << "Error Nr. " << err.id << std::endl
		<< "At: " << std::put_time(&error_time, "%F %T") << std::endl
		<< "in: " << err.location << std::endl
		<< err.error_name << std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl;
	return os;
}
