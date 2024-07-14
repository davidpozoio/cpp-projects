#include <iostream>

int main()
{
    const int size = 5;

    int **array = new int *[size];

    for (int i = 0; i < size; i++)
    {
        *(array + i) = new int;
        **(array + i) = 5;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << *array[i] << std::endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete *(array + i);
    }

    delete[] array;
}