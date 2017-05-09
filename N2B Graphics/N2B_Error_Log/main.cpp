#include "NB_Error_Log.h"
#include <iostream>

int main()
{
	NB::NB_Error_Log err_Log;

	try
	{
		err_Log.set_log_name("**?!\"");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	char ch;
	std::cin >> ch;
}