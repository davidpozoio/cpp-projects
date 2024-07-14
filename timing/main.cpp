#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <string>

struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        double ms = duration.count() * 1000.0f;
        std::cout << "time took " << ms << "ms" << std::endl;
    }
};

void print()
{
    Timer timer;
    std::string output = "";
    for (int i = 0; i < 10000; i++)
        output += "hello world";
    std::cout << output;
}

int main()
{
    print();
}