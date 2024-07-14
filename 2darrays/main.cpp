#include <iostream>

int main()
{
    int *array = new int[10];
    int *array2 = new int[10];
    int **matrix = new int *[10];

    *(matrix + 0) = array;
    *(matrix + 1) = array2;

    std::cout << *(*(matrix + 0) + 1) << std::endl;
}