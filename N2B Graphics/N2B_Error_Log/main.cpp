#include "NB_Error_Log.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
void error_test();


NB::NB_Error_Log NB_Err;
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
		std::cerr << "Error: " << e.what();
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "End!" << std::endl;

	char ch;
	std::cin >> ch;
}


void error_test() 
{
	for (int i = 0; i < 10; i++)
	{
		std::stringstream info;
		std::this_thread::get_id()._To_text(info);
		NB_Err.log(NB::NB_FATAL_ERROR, "error_test " + std::to_string(i), "Test Error! \nThread: " + info.str());
	}
}