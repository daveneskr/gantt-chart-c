#include <stdio.h>
#include <string.h>

#include "ascii_art.h"
#include "dependency.h"
#include "tasks.h"
#include "display_Gantt.h"
#include "my_library.h"

int main(void)
{
    /******************** SECTION 0 *****************
     * define and initialize variables used throughtout the main
     ************************************************/

    Task tasks[MAX_TASKS]; // initialize tge task array
    unsigned int num_tasks; // number of tasks
    char response[20];

    /******************** SECTION 1 *****************
     * getting input from user about each task
     * storing the data in structure data type
     * testing for valid input
     ************************************************/

    // Sets up the program at the beginning, get values for Tasks
    // 1. Ask user where to get values for tasks
    //   a) user input - prompts user to get details about each task
    //   b) test values - inputs test values to struct tasks
    // 2. Stores values in Task tasks
    initial_action(tasks, &num_tasks);

    // Displays the Gantt diagram of the tasks
    display_Gantt_diagram(tasks, num_tasks);

    /******************** SECTION 2 *****************
    * menu-like state, where user is offer actions
    * editing, tasks, checking dependencies
    * quiting the program
    ************************************************/

    // continue offer action option to user until the program is quit
    do
    {
        puts("\nIf you wish to edit the Gantt please type \"edit\" "
        "/ If you wish to run a test, type \"test\" "
        "or to exit, type \"quit\" and then press enter to execute your option.");
        scanf("%s", response);

        // if user chooses to edit
        if (strcmp("edit", response) == 0)
        {
            // prompts user to edit a task
            action_edit(tasks, &num_tasks);
            // clears the previous Gantt diagram
            clear_screen();
            // displays Gantt with edited task
            display_Gantt_diagram(tasks, num_tasks);
        }
        else if (strcmp("test", response) == 0)
        {
            // ask user which task they would like to test
            puts("Enter the name of the task you would like to test:");
            scanf("%s", response);
            // look through tasks to find one matching to response
            for (unsigned int i = 0; i < num_tasks; i++)
            {
                if (strcmp(tasks[i].name, response) == 0)
                {
                    // print dependency chain
                    printf("\nDependency Chain:\n");
                    int visited[MAX_TASKS] = {0}; // track visited tasks
                    print_dependency_chain(tasks, tasks[i].id, visited);
                }
            }
        }
    } while (strcmp("quit", response) != 0);

    /******************** SECTION 3 *****************
    * final section, where the screen is cleared
    * and ascii art is displayed
    ************************************************/

    // clear screen from program output
    clear_screen();

    // display ascii art
    print_ascii_art();

    return(0);
}
