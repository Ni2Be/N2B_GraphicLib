#pragma once
#include <vector>
#include <ctime>
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
		int id;

		friend std::ostream& operator<<(std::ostream& os, const Error& err);
	};
	std::ostream& operator<<(std::ostream& os, const Error& err);

	template <class T>
	class Thread_Queue : std::queue<T>
	{
		friend class NB_Error_Log;
		std::mutex mutex;
	};

	class NB_Error_Log
	{
	public:
		NB_Error_Log();
		~NB_Error_Log();
		

		void set_log_name(const std::string log_file_name);
		void set_final_log_name(const std::string final_log_file_name);

		void log(NB_Error signature, const std::string location, const std::string error);
		void print_errors(bool emty_queue = false);

	private:
		[[noreturn]] void handle_work();
		void get_queue_ready();
		void save_error(const Error& err, std::ofstream& file);
		void open_file_append(const std::string& file_name, std::ofstream& file);

		bool is_name_valid(const std::string file_name);

		std::string log_file_name;
		std::string final_log_file_name;

		int error_id;
		std::vector<Error*> log_vec;
		Thread_Queue<Error*> work_q;
		std::thread work_handler;
		bool is_running;
	};


}