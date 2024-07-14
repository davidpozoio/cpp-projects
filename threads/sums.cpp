#include <iostream>
#include <thread>
#include <chrono>

class Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

public:
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000;
        std::cout << "time took: " << ms << "ms" << std::endl;
    }
};

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

ull odd(ull start, ull end)
{
    ull sum = 0;

    for (ull i = start; i <= end; i++)
    {

        if (i % 2 == 1)
        {
            oddSum += i;
        }
    }

    return sum;
}

ull even(ull start, ull end)
{
    ull sum = 0;

    for (ull i = start; i <= end; i++)
    {

        if (i % 2 == 0)
        {
            evenSum += i;
        }
    }

    return sum;
}

int main()
{
    Timer timer;

    ull start = 0, end = 1900000000;

    std::thread t1(odd, start, end);
    std::thread t2(even, start, end);

    t1.join();
    t2.join();

    std::cout << "even sum: " << evenSum << std::endl;
    std::cout << "odd sum: " << oddSum << std::endl;
}