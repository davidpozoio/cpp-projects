#include "utils.h"
#include <chrono>
#include <thread>

void Utils::delay(std::chrono::milliseconds milliseconds)
{
    std::this_thread::sleep_for(milliseconds);
}