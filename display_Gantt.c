//
// Created by David Neškrabal on 06.03.2025.
//

#include <stdio.h>
#include <string.h>

#include "display_Gantt.h"

void print_char(char a)
{
    // print character (size of big header cell, month header cell * 12, dependencies header cell) times
    for (int k = 0; k < (12 * 11) + 21 + 13; k++)
    {
        printf("%c", a);
    }
    printf("\n");
}

void print_cell(char *string, int width)
{
    int length = strlen(string);  // get length of the string
    // calculate how much white space should be on each side
    int white_space = (length >= width) ? 0 : (width - length) / 2;
    int extra_padding = (length >= width) ? 0 : (width - length) % 2;  // handle odd cases

    printf("|%*s%s%*s", white_space, "", string, white_space + extra_padding, "");
}

void print_header(void)
{
    print_char('_'); // print separation line
    printf("%20s", ""); // print first cell (empty space)
    // initialize months array of strings
    char columns[][13] = { "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December", "Dependencies"};

    // print column header for each month
    for (int i = 0; i < 13; i++)
    {
        print_cell(columns[i],10);
    }
    printf("|\n");
    print_char('-'); // print separation line
}

void display_Gantt_diagram(Task tasks[], int num_tasks)
{
    int i, j; // initialize loop counter variables

    // prints the gantt diagram's header
    print_header();

    // print row for each task, depicting in which months is the task being worked on
    for (i = 0; i < num_tasks; i++)
    {
        printf("%-25s", tasks[i].name); // Print task name aligned

        // print a cell for each month filling the cell if the task
        // is being worked on that month
        for (j = 1; j <= 12; j++)
        {
            // check if j which represents the current month is
            // within range of start and end month
            if (j >= tasks[i].start_month && j <= tasks[i].end_month)
            {
                print_cell("XXX", 10); // fill the cell with x's
            }
            // keep the cell empty
            else
            {
                print_cell("", 10);
            }
        }
        printf("|"); // box of the last cell

        // prints the dependenies
        for (j = 0; j < tasks[i].dependencies; j++)
        {
            printf(" %u", tasks[i].dependency_id[j]+1);
        }
        printf("\n");
        print_char('-'); // prints separations line
    }
}