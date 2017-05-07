#include "NB_Error_Log.h"
#include <iostream>

int main()
{
	NB::NB_Err.add_err("Test0");
	NB::NB_Err.add_err("Test1");
	NB::NB_Err.add_err("Test2");
	NB::NB_Err.add_err("Test3");

	char ch;
	std::cin >> ch;
}