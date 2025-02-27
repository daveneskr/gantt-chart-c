//
// Created by David Neškrabal on 20.02.2025.
//

#include "my_library.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void display_menu(void)
{
    printf("%s\n", "Welcome to the Gantt Generator\n"
    "Would you like to use the test example or create your on Gantt from scratch? (test or create)");
}

void initialize_test_values(Task tasks[], unsigned int *num_tasks)
{
    *num_tasks = 5; // Example: Setting 5 predefined tasks

    tasks[0] = (Task){1, "Design", 1, 3, 0, {}};
    tasks[1] = (Task){2, "Development", 4, 8, 1, {1}};
    tasks[2] = (Task){3, "Testing", 9, 10, 1, {2}};
    tasks[3] = (Task){4, "Deployment", 12, 12, 2, {2, 3}};
    tasks[4] = (Task){5, "Review", 11, 12, 1, {3}};
}

void print_cell(char *string, int width)
{
    int length = strlen(string);  // get length of the string
    // calculate how much white space should be on each side
    int white_space = (length >= width) ? 0 : (width - length) / 2;
    int extra_padding = (length >= width) ? 0 : (width - length) % 2;  // handle odd cases

    printf("|%*s%s%*s", white_space, "", string, white_space + extra_padding, "");
}

void print_char(char a)
{
    // print character (size of big header cell, month header cell * 12, dependencies header cell) times
    for (int k = 0; k < (12 * 11) + 21 + 13; k++)
    {
        printf("%c", a);
    }
    printf("\n");
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

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a; // store a in tmp to prevent overwriting data
    *a = *b;
    *b = tmp;
}

void bubble_sort(unsigned int arr[], unsigned int size)
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
            printf("Please enter dependent task (%d/%u):", i+1, *num_dependency);
            scanf("%u", &dependency_id[i]); // store task id's in an array
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

        // call function to get months input to the current task from user
        get_months(&tasks[i].start_month, &tasks[i].end_month);

        // call function to get dependency input to the current task from user
        get_dependencies(&tasks[i].dependencies, tasks[i].dependency_id);
    }
}

void display_Gantt_diagram(Task tasks[], int num_tasks)
{
    int i, j; // initialize loop counter variables

    // prints the gantt diagram's header
    print_header();

    // print row for each task, depicting in which months is the task being worked on
    for (i = 0; i < num_tasks; i++)
    {
        printf("%-20s", tasks[i].name); // Print task name aligned

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
            printf(" %u", tasks[i].dependency_id[j]);
        }
        printf("\n");
        print_char('-'); // prints separations line
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