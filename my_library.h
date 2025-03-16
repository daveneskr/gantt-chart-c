//
// Created by David Neškrabal on 20.02.2025.
//

#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#define MAX_TASKS 10

/* Swaps the two values
 * - int *a: a pointer to the variable to be swapped with b
 * - int *b: -||-
 */
void swap(int *a, int *b);

/* Uses the bubble sort algorithm to store an array of numbers
 * - int arr[]: the array to sort
 * - int size: size of the array
 */
void bubble_sort(int arr[], int size);

/*
 * Function    : clear_screen
 * Description : Clear console output, supports Windows, Linux, macOS, and other platforms.
 */
void clear_screen(void);

void clear_stdin(void);

#endif //MY_LIBRARY_H
