#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_library.h"

/************ TO-DO's *************
 * add initial welcome and option for test or own values (mentioned in Assignment 2 - Specification (2025).pdf
 * check if input from user regarding months is within <1,12>
 * consider changing print_month to be more general
 *     - ie. return_type char so that it can be used within printf
 *     - rename
 * do input month function
 * A) 2) from Assignment 2 - Specification (2025).pdf
 * A) 3) from Assignment 2 - Specification (2025).pdf
 * A) 4) from Assignment 2 - Specification (2025).pdf
 **********************************/

int main(void)
{
    /******************** SECTION 0 *****************
     * define and initialize variables used throughtout the main
     ************************************************/
    Task tasks[MAX_TASKS];
    unsigned int num_tasks; // number of tasks
    char response[20];

    /******************** SECTION 1 *****************
     * getting input from user about each task
     * storing the data in structure data type
     * testing for valid input
     ************************************************/
    initial_action(tasks, &num_tasks);

    display_Gantt_diagram(tasks, num_tasks);


    puts("If you wish to edit the Gantt please type \"edit\" "
    "/ If you wish to run a test, type \"test\" "
    "or to exit, type \"quit\" and then press enter to execute your option.");
    scanf("%s", response);

    if (strcmp("edit", response) == 0)
    {
        action_edit(tasks, &num_tasks);
        display_Gantt_diagram(tasks, num_tasks);
    }



    return(0);
}
