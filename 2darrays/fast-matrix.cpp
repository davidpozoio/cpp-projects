#include <iostream>
#include <chrono>

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
        const double ms = duration.count() * 1000.0f;
        std::cout << "time took " << ms << "ms" << std::endl;
    }
};

void createLowMatrix()
{
    Timer timer;

    int **matrix = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        *(matrix + i) = new int[5];
        for (int j = 0; j < 5; j++)
        {
            *(*(matrix + i) + j) = 5;
            std::cout << *(*(matrix + i) + j);
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        delete[] *(matrix + i);
    }

    delete[] matrix;
}

void createMatrix()
{
    Timer timer;
    const int cols = 5, rows = 5;

    int *matrix = new int[rows * cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(matrix + j + i * cols) = 5;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << *(matrix + j + i * cols);
        }

        std::cout << std::endl;
    }

    delete[] matrix;
}

int main()
{
    createLowMatrix();
    createMatrix();
}