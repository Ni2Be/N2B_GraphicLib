#pragma once
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <queue>

namespace NB
{
	enum NB_Error
	{
		NB_FATAL_ERROR = 1,
		NB_WARNING = 1 << 1,
		NB_ERROR =  1 << 2
	};

	class Error
	{
		friend class NB_Error_Log;
	private:
		Error(NB_Error signature, const std::string location, const std::string error);
		NB_Error signature;
		std::string location;
		std::string error_name;
		std::time_t time_stamp;


		friend std::ostream& operator<<(std::ostream& os, const Error& err);
	};
	std::ostream& operator<<(std::ostream& os, const Error& err);

	class NB_Error_Log
	{
	public:
		NB_Error_Log();
		~NB_Error_Log();
		
		
		void log(NB_Error signature, const std::string location, const std::string error);
		void print_errors();

	private:
		[[noreturn]] void handle_work();
		void save_error(const Error& err);
		std::mutex mutex;
		std::vector<Error*> log_vec;
		std::queue<Error*> work_q;
	};

	static NB_Error_Log NB_Err;
}