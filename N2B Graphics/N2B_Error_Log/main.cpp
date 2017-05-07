#include "NB_Error_Log.h"
#include <iostream>
#include <string>
#include <thread>

void error_test();

int main()
{
	try
	{
		std::thread t1(error_test);
		std::thread t2(error_test);
		std::thread t3(error_test);
		std::thread t4(error_test);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}


void error_test() 
{
	for (int i = 0; i < 10000; i++)
		NB::NB_Err.log(NB::NB_FATAL_ERROR, "error_test", "Test Error!");
}