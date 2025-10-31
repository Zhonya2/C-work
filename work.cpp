#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

std::string check_assignment(std::string student_name)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int score = 60 + rand() % 41;
    return "Студент " + student_name + " отримав " + std::to_string(score) + " балів.";
}

int main()
{
    srand(time(nullptr));

    std::future<std::string> result1 = std::async(std::launch::async, check_assignment, "Іван");
    std::future<std::string> result2 = std::async(std::launch::async, check_assignment, "Олена");

    std::cout << "Головний потік: Оцінюю наступне завдання...\n";

    std::string res1 = result1.get();
    std::string res2 = result2.get();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;

    return 0;
}
