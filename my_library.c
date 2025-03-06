//
// Created by David Neškrabal on 20.02.2025.
//

#include <stdlib.h>

#include "my_library.h"

void swap(int *a, int *b)
{
    int tmp = *a; // store a in tmp to prevent overwriting data
    *a = *b;
    *b = tmp;
}

void bubble_sort(int arr[], int size)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/*
 * Function    : clear_screen
 * Description : Clear console output, supports Windows, Linux, macOS, and other platforms.
 */
void clear_screen(void)
{
#if defined(_WIN32) || defined(_WIN64)

    // Windows
    system("cls");

#elif defined(__linux__) || defined(__APPLE__)

    // Linux & macOS
    system("clear");

#else

    // Other situations
    system("clear");

#endif
}
