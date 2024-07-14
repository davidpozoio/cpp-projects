#include <iostream>

namespace apple
{
    void print()
    {
        std::cout << "hello apple" << std::endl;
    }
}

namespace orange
{
    void print()
    {
        std::cout << "hello orange" << std::endl;
    }
}

int main()
{
    apple::print();
}