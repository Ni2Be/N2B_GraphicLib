#pragma once
#include <vector>
#include <chrono>

namespace NB
{
	enum NB_Error
	{
		NB_FATAL_ERROR = 1,
		NB_WARNING = 1 << 1
	};

	class NB_Error_Log
	{
	public:
		NB_Error_Log() {}
		~NB_Error_Log();
		
		
		void log(NB_Error signature, const std::string location, const std::string error);
	private:
		struct Error
		{
			Error(NB_Error signature, const std::string location, const std::string error);
			NB_Error signature;
			std::string location;
			std::string error_name;
			std::chrono::time_point<std::chrono::system_clock> time_stamp;

			std::ostream operator<<(std::ostream& os)
			{
				os << 
			}
		};

		std::vector<Error> log_vec;
	};

	static NB_Error_Log NB_Err;
}