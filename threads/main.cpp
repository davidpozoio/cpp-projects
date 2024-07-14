#include <iostream>
#include <thread>
#include <chrono>

void delay(std::chrono::milliseconds milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

bool isFinished = false;

void doWork()
{
    while (!isFinished)
    {
        std::cout << "hello" << std::endl;
    }
    delay((std::chrono::milliseconds)3000);
}

int main()
{
    std::thread worker(doWork);

    std::cin.get();
    isFinished = true;

    worker.join();
}