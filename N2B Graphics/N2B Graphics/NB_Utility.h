#pragma once
#include <string>

#include "../N2B_Error_Log/NB_Error_Log.h"

void error_log(const std::string location, const std::string error);

std::string load_file_to_string(const std::string& fileName);
