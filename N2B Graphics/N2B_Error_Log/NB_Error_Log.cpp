#include "NB_Error_Log.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <iterator>

//CLASS ERROR
/*
An error can only be initialized with all information the Log needs
A time stamp will be set at the moment of creation.
This moment can take a view miliseconds because the thread work_handler
can lock the work queue.
*/
NB::Error::Error(NB_Error signature, const std::string location, const std::string error)
	:signature(signature), location(location), error_name(error)
{
	//set time
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	this->time_stamp = std::chrono::system_clock::to_time_t(now);
}

/*
The output operator will print the log with seperation lines on it's bottom
*/
std::ostream& NB::operator<<(std::ostream& os, const Error& err)
{
	std::tm error_time;
	localtime_s(&error_time, &err.time_stamp);
	os << "Error Nr. " << err.id << std::endl
		<< "At: " << std::put_time(&error_time, "%F %T") << std::endl
		<< "in: " << err.location << std::endl
		<< err.error_name << std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl
		<< "------------------------------------------------------------------------------------"
		<< std::endl;
	return os;
}

//CLASS ERROR_LOG
/*
When NB_Error_Log is initialized it will start his work handler
and new logs can be added with the function log()
*/
NB::NB_Error_Log::NB_Error_Log(const std::string log_name,
	const std::string final_log_name) 
	: is_running(true),
	log_file_name(log_name),
	final_log_file_name(final_log_name),
	error_id(0)
{
	work_handler = std::thread(&NB::NB_Error_Log::handle_work, this);
}

/*
When the log is destroied it will ensure that the thread work_handler
has consumed all waiting errors of the work_q.
After that it will try to save a final version of the error log. If it
fails it will put the information to the cerr console
*/
NB::NB_Error_Log::~NB_Error_Log()
{
	//inform the thread work_handler that the program wants to close
	is_running = false;

	//wait for the work_handler to become joinable
	bool is_waiting = true;
	while (is_waiting)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (!work_handler.joinable())
			is_waiting = false;
	}

	//try to save to file
	//show on console if failed
	std::ofstream file;
	if (log_vec.size() > 0)
		file.open(final_log_file_name, std::ios::out);
	if (!file)
	{
		std::cerr << "\nNot able to save Error Log:\n";
		for (auto& i : log_vec)
			std::cerr << *i << std::endl;
	}
	else
	{
		for (auto& itr = std::rbegin(log_vec); itr < std::rend(log_vec); itr++)
		{
			file << **itr << std::endl;
		}
	}

	//clean up
	for (auto& i : log_vec)
		delete i;
}

/*
Prints all handeles errors to console
*/
void NB::NB_Error_Log::print_errors(bool emty_queue)
{
	std::unique_lock<std::mutex> guard(work_q.mutex, std::defer_lock);
	if (emty_queue)
	{
		get_queue_ready();
	}

	std::cout << "\nErrors:\n\n";
	for (auto& i : log_vec)
		std::cout << *i << std::endl; 
	
	guard.lock();
	int wk_s = work_q.size();
	guard.unlock();

	if (wk_s > 0)
		std::cout << "\nThere are still " << wk_s << " Errors in the work_q\n"
		"Use argument \"true\" to empty\n";

}

/*
saves an error to a given file
*/
void NB::NB_Error_Log::save_error(const Error& err, std::ofstream& file)
{
	file << err << std::endl;
}

/*
Opens an file in append mode, prints error to console if failed
*/
void NB::NB_Error_Log::open_file_app(const std::string& file_name, std::ofstream& file)
{
	file.open(file_name, std::ios::app);
	if (!file.is_open())
		std::cerr << "\nCould not open " + file_name << std::endl;
}

/*
Will push an error to the work_queue as fast as possible
*/
void NB::NB_Error_Log::log(NB_Error signature, const std::string location, const std::string error)
{
	std::unique_lock<std::mutex> guard(work_q.mutex, std::defer_lock);
	guard.lock();
	work_q.push(new Error(signature, location, error));
	guard.unlock();
}

/*
Is only used by the thread work_handler.
handel means it pushes the Errors into a vector and appends it to a file.

Will emty the work_queue with as less as possible time owning it.
To do so it handles only one Error per second.

If the programm terminates it will handle the remaining 
Errors as fast as possible.
*/
void NB::NB_Error_Log::handle_work()
{
	std::unique_lock<std::mutex> guard(work_q.mutex, std::defer_lock);
	while (true)
	{
		//sleep for one second
		std::this_thread::sleep_for(std::chrono::seconds(1));

		//lock to get size
		guard.lock();
		if (work_q.size() > 0)
		{
			//unlock if size was > 0
			guard.unlock();

			//open file while unlocked
			std::ofstream file;
			open_file_app(log_file_name, file);

			//lock and get the Error*
			guard.lock();
			Error* err = work_q.front();
			guard.unlock();

			//set id
			err->id = error_id++;

			//push to the vector and save while unlocked
			log_vec.push_back(err);
			save_error(*err, file);

			//lock to pop front
			guard.lock();
			work_q.pop();
		}
		//unlock if size was 0
		guard.unlock();


		//if the Desructor was called clean up the queue
		if (!is_running)
		{
			get_queue_ready();

			work_handler.detach();
			work_handler.~thread();
		}
	}
}

/*
Will lock the queue.
Does the same as handle_work but faster and without
unlocking between all steps
*/
void NB::NB_Error_Log::get_queue_ready()
{
	std::unique_lock<std::mutex> guard(work_q.mutex, std::defer_lock);
	guard.lock();
	std::ofstream file;
	if (work_q.size() > 0)
	{
		open_file_app(log_file_name, file);
	}
	while (work_q.size() > 0)
	{
		Error* err = work_q.front();

		err->id = error_id++;
		
		log_vec.push_back(err);
		save_error(*err, file);

		work_q.pop();
	}
	guard.unlock();
}
