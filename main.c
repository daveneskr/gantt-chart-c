#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_library.h"
#include "dependecy.h"

#ifdef _WIN32
#define system("clear); system("cls")
#endif

/************ TO-DO's *************

- Make a recursive function that creates a chain of dependencies and
  checks for circular dependency
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

    do
    {
        puts("\nIf you wish to edit the Gantt please type \"edit\" "
        "/ If you wish to run a test, type \"test\" "
        "or to exit, type \"quit\" and then press enter to execute your option.");
        scanf("%s", response);

        if (strcmp("edit", response) == 0)
        {
            action_edit(tasks, &num_tasks);
            system("clear");
            display_Gantt_diagram(tasks, num_tasks);
        }
        else if (strcmp("test", response) == 0)
        {
            puts("Enter the name of the task you would like to test:");
            scanf("%s", response);
            for (unsigned int i = 0; i < num_tasks; i++)
            {
                if (strcmp(tasks[i].name, response) == 0)
                {
                    // Print dependency chain
                    printf("\nDependency Chain v.1:\n");
                    int visited[MAX_TASKS] = {0}; // track visited tasks
                    print_dependency_chain(tasks, tasks[i].id, visited);
                }
            }
        }
    } while (strcmp("quit", response) != 0);

    system("clear");

    return(0);
}
