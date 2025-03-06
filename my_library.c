//
// Created by David Neškrabal on 20.02.2025.
//

#include <stdlib.h>

#include "my_library.h"

/* Swaps the two values
 * - int *a: a pointer to the variable to be swapped with b
 * - int *b: -||-
 */
void swap(int *a, int *b)
{
    int tmp = *a; // store a in tmp to prevent overwriting data
    *a = *b;
    *b = tmp;
}

/* Uses the bubble sort algorithm to store an array of numbers
 * - int arr[]: the array to sort
 * - int size: size of the array
 */
void bubble_sort(int arr[], int n)
{
    int i, j, swapped;
    // loop used to keep count of how many swaps
    // where already performed
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // used to check if array is already sorted
        // compare two  adjacent elements
        // and swap them if the first one is bigger
        // the guard accounts for elements at the end of the array
        // that where already sorted ("bubbled up")
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        // if no two elements were swapped, array is already sorted
        if (swapped == 0)
        {
            return;
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
