/*
NB_Utility:
Attention:
Purpose:
Usage:
*/

#ifdef NB_PRAGMA_ONCE_SUPPORT
#pragma once
#endif
#ifndef NB_UTILITY_H_INCLUDED
#define NB_UTILITY_H_INCLUDED
#include <string>

#include "../N2B_Error_Log/NB_Error_Log.hpp"

namespace NB
{
	void error_log(const std::string location, const std::string error);

	std::string load_file_to_string(const std::string& fileName);

}
#endif
