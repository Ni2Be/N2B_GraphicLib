//#include "NB_Error_Log.hpp"
//#include <iostream>
//void test_err();
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
//int main()
//{
//	err_Log.set_log_rate(std::chrono::microseconds(1000));
//	std::thread th1(test_err);
//	std::thread th2(test_err);
//
//	th1.join();
//	th2.join();
//
//	char ch;
//	std::cin >> ch;
//}
//
//
//void test_err()
//{
//	for (int i = 0; i < 10; i++)
//		err_Log.log(new NB::Error(NB::NB_ERROR, "main()", "Test_Error"));
//}