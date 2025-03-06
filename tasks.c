//
// Created by David Neškrabal on 06.03.2025.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tasks.h"
#include "my_library.h"

void display_menu(void)
{
    printf("%s\n", "Welcome to the Gantt Generator\n"
    "Would you like to use the test example or create your own Gantt from scratch? (test or create)");
}

void initialize_test_values(Task tasks[], unsigned int *num_tasks)
{
    *num_tasks = 10;

    tasks[0] = (Task){0, "Find_Bank", 1, 2, 0, {}};
    tasks[1] = (Task){1, "Get_mortage_approval", 2, 2, 1, {0}};
    tasks[2] = (Task){2, "Draw_Down", 4, 6, 3, {0,1,4}};
    tasks[3] = (Task){3, "Build_Foundation", 3, 4, 1, {2}};
    tasks[4] = (Task){4, "Build_Walls", 4, 5, 0, {}};
    tasks[5] = (Task){5, "Roof_and_ceiling", 5, 6, 2, {3,4}};
    tasks[6] = (Task){6, "Plumbing", 7, 7, 1, {5}};
    tasks[7] = (Task){7, "Electrics", 8, 9, 1, {6}};
    tasks[8] = (Task){8, "Inspect_Build", 9, 10, 1, {4}};
    tasks[9] = (Task){9, "Snagging", 10, 11, 2, {7,8}};

}

void get_months(unsigned int * start_month, unsigned int * end_month)
{
    // keep prompting user to get starting month until valid input is inserted (1-12)
    do
    {
        puts("Please enter the starting month (1-12):");
        scanf("%u", start_month); // store number in start_month

    } while (*start_month < 1 || *start_month > 12);

    //  keep prompting user to get starting month until valid
    //  input is inserted (1-12) and more or equal to start_month
    do
    {
        puts("Please enter the ending month (1-12):");
        scanf("%u", end_month);

        // inform user of incorrect input
        if (*end_month < *start_month)
        {
            puts("End month cannot be before start month. Try again.");
        }

    } while (*end_month < *start_month || *end_month > 12);
}

void get_dependencies(unsigned int * num_dependency, unsigned int dependency_id[])
{
    // Ask if there are any dependencies
    puts("Please enter how many dependencies this task has:");
    scanf("%u", num_dependency);
    if (*num_dependency != 0) // if there are any dependencies, ask to which tasks
    {
        // prompt user to get the task numbers the current task is dependent on
        for (int i = 0; i < *num_dependency; i++)
        {
            printf("Please enter dependent task (%d/%u):\n", i+1, *num_dependency);
            scanf("%u", &dependency_id[i]); // store task id's in an array
            dependency_id[i]--; // adjust to start counting from zero
        }
    }
    bubble_sort(dependency_id, *num_dependency); // sort id's
}

void get_Task_data(Task tasks[], unsigned int * num_tasks)
{
    int i;

    // prompt user to insert the number of tasks
    puts("How many tasks would you like to add? (1-10)");
    scanf("%u", num_tasks); // store num of tasks in num_tasks
    // prompt user to input details about each task
    for (i = 0; i < *num_tasks; i++)
    {
        // Prompts user to Enter task name
        puts("Please enter the task name:");
        scanf("%s", tasks[i].name); // store name in char array

        // Initialize task id
        tasks[i].id = i;

        // call function to get months input to the current task from user
        get_months(&tasks[i].start_month, &tasks[i].end_month);

        // call function to get dependency input to the current task from user
        get_dependencies(&tasks[i].dependencies, tasks[i].dependency_id);
    }
}

void initial_action(Task tasks[], unsigned int *num_tasks)
{
    char response[20];
    bool finished = false;

    // display welcome message
    display_menu();

    // continue getting input from user until valid input is inserted
    do
    {
        scanf("%s", response); // get user input

        // check if user wants to work with testing values
        if (strcmp(response, "test") == 0)
        {
            initialize_test_values(tasks, num_tasks); // inputs test values to struct tasks
            finished = true; // assign true to finished to exit the do-while loop
        }
        else if (strcmp(response, "create") == 0)
        {
            // prompts user get details about each task
            get_Task_data(tasks, num_tasks);
            finished = true; // assign true to finished to exit the do-while loop
        }
        else
        {
            // inform user that wrong input has been given
            puts("Wrong input - Enter \"test\" or \"create\"");
        }
    } while (!finished);
}

void action_edit(Task tasks[], unsigned int *num_tasks)
{
    char response[20];
    int i;
    bool found = false;

    do
    {
        puts("Please enter the task name you wish to change exactly");
        scanf("%s", response);

        for (i = 0; i < *num_tasks; i++)
        {
            if (strcmp(tasks[i].name, response) == 0)
            {
                found = true;
                break;
            }
        }
    } while (!found);

    puts("Please enter the new task or write its old one");
    scanf("%s", tasks[i].name);

    get_months(&tasks[i].start_month, &tasks[i].end_month);

    get_dependencies(&tasks[i].dependencies, tasks[i].dependency_id);
}