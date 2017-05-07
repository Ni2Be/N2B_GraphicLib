#pragma once
#include <string>

void error_log(const std::string location, const std::string error);

std::string load_file_to_string(const std::string& fileName);
