//#include "NB_Error_Log.hpp"
//#include <iostream>
//#include <gtest/gtest.h>
//
//void test_err();
//
//
//class My_Error
//{
//public:
//	My_Error(const std::string location)
//	:location(location) {}
//	std::string location;
//	int id;
//
//	friend std::ostream& operator<<(std::ostream& os, const My_Error& err);
//};
//std::ostream& operator<<(std::ostream& os, const My_Error& err)
//{
//	return os << err.id << " Test" << std::endl << err.location << std::endl;
//}
//
//
//
//
//NB::NB_Error_Log<> err_Log;
//int main(int argc, char* argv[])
//{
//	std::thread th1(test_err);
//	std::thread th2(test_err);
//	std::thread th3(test_err);
//	std::thread th4(test_err);
//	std::thread th5(test_err);
//	std::thread th6(test_err);
//
//	th1.join();
//	th2.join();
//	th3.join();
//	th4.join();
//	th5.join();
//	th6.join();
//
//	char ch;
//	std::cin >> ch;
//}
//
//
//void test_err()
//{
//	for (int i = 0; i < 1; i++)
//		err_Log.err_log(NB::NB_Error(NB::NB_ERROR, "main()", "Test_Error"));
//}