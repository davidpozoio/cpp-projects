#include <iostream>

int main()
{
    int **matrix = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        *(matrix + i) = new int[5];
        for (int j = 0; j < 5; j++)
        {
            *(*(matrix + i) + j) = 5;
            std::cout << *(*(matrix + i) + j) << std::endl;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        delete[] *(matrix + i);
    }

    delete[] matrix;
}