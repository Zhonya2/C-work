#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <chrono>
#include <mutex>

#include "condition_variable_custom.h"

c_condition_variable simple_cv;

std::mutex mtx;

bool ready = false;

void worker(int id)
{
	std::unique_lock<std::mutex> lock(mtx);

	simple_cv.wait(lock, []
				   { return ready; });

	std::cout << "Thread # " << id << " woke up!\n";
}

// long long counter = 0;  //POD - types
//
// std::atomic<long long> safe_counter = 0;
//
// const long long ARRAY_SIZE = 1000'000;
//
// std::vector<int> arr(ARRAY_SIZE, 1);
//
// void increment_unsafe(volatile long long& c)
//{
//	//mtx.lock();
//
//	//----------CRITICAL SECTION-------------------
//	//read
//	volatile long long temp = c;
//
//	//edit
//	for (int i = 0; i < 100'000; ++i)
//	{
//		temp++;
//		//-----------
//		temp--;
//	}
//	//--------------------
//	temp = temp + 1;
//
//	//write
//	c = temp;
//
//	//----------CRITICAL SECTION-------------------
//	//mtx.unlock();
// }
//
// void increment_safe()
//{
//	safe_counter++;
// }
//
// void count(size_t start, size_t end)
//{
//	for (size_t i = start; i < end; i++)
//	{
//		//if (arr[i] % 2 == 0)
//			//counter++;
//		//increment_unsafe(counter);
//		increment_safe();
//	}
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
// }
//
// void new_task()
//{
//	mtx.lock();
//	if (safe_counter >= 500'000)
//	{
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	}
//	else
//	{
//		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//	}
//	mtx.unlock();
// }

int main()
{
	std::vector<std::thread> threads;

	for (int i = 0; i < 5; i++)
	{
		threads.emplace_back(worker, i + 1);
	}

	std::cout << "Main thread: sleeping 2 seconds...\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

	{
		std::lock_guard<std::mutex> lock(mtx);
		ready = true;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Main thread: notify_one()\n";
		simple_cv.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	for (auto &th : threads)
		th.join();

	std::cout << "All threads finished.\n";
	return 0;
}
