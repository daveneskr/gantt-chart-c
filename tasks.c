//
// Created by David Neškrabal on 06.03.2025.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tasks.h"
#include "my_library.h"

/* Displays the welcoming message and users options
 */
void display_menu(void)
{
    printf("%s\n", "Welcome to the Gantt Generator\n"
    "Would you like to use the test example or create your own Gantt from scratch? (test or create)");
}

/* Initialize an array of Task's with test values
 * - Task tasks[]: The array you want the test values to be stored in
 * - unsigned int *num_tasks: The number of tasks of the test values
 */
void initialize_test_values(Task tasks[], unsigned int *num_tasks)
{
    *num_tasks = 10;

    // enum statement for clearer identification of tasks
    enum Task_ID {
        FIND_BANK,
        GET_MORTGAGE_APPROVAL,
        DRAW_DOWN,
        BUILD_FOUNDATION,
        BUILD_WALLS,
        ROOF_AND_CEILING,
        PLUMBING,
        ELECTRICS,
        INSPECT_BUILD,
        SNAGGING
    };

    tasks[0] = (Task){FIND_BANK, "Find_Bank", 1, 2, 0, {}};
    tasks[1] = (Task){GET_MORTGAGE_APPROVAL, "Get_mortage_approval", 2, 2, 1, {FIND_BANK}};
    tasks[2] = (Task){DRAW_DOWN, "Draw_Down", 4, 6, 2, {FIND_BANK,GET_MORTGAGE_APPROVAL}};
    tasks[3] = (Task){BUILD_FOUNDATION, "Build_Foundation", 3, 4, 1, {DRAW_DOWN}};
    tasks[4] = (Task){BUILD_WALLS, "Build_Walls", 4, 5, 0, {}};
    tasks[5] = (Task){ROOF_AND_CEILING, "Roof_and_ceiling", 5, 6, 2, {BUILD_FOUNDATION,BUILD_WALLS}};
    tasks[6] = (Task){PLUMBING, "Plumbing", 7, 7, 1, {ROOF_AND_CEILING}};
    tasks[7] = (Task){ELECTRICS, "Electrics", 8, 9, 1, {PLUMBING}};
    tasks[8] = (Task){INSPECT_BUILD, "Inspect_Build", 9, 10, 1, {BUILD_WALLS}};
    tasks[9] = (Task){SNAGGING, "Snagging", 10, 11, 2, {ELECTRICS,INSPECT_BUILD}};

}

/* Prompts user to input start/end month
 * and store them in the Task structure
 * - unsigned int * start_month: number representing the start month
 * - unsigned int * end_month: number representing the end month
 */
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

        // checks the validity of the end month
    } while (*end_month < *start_month || *end_month > 12);
}

/* Gets information about the dependencies of a task
 * - unsigned int * num_dependency: The number of dependencies of a task
 * - unsigned int dependency_id[]: array to store the id of the dependent tasks
 * - int num_tasks: Overall number of tasks
 */
void get_dependencies(unsigned int * num_dependency, unsigned int dependency_id[], int num_tasks)
{
    // Ask if there are any dependencies
    puts("Please enter how many dependencies this task has:");
    scanf("%u", num_dependency);
    if (*num_dependency != 0) // if there are any dependencies, ask to which tasks
    {
        // prompt user to get the task numbers the current task is dependent on
        for (int i = 0; i < *num_dependency; i++)
        {
            do
            {
                printf("Please enter dependent task (%d/%u):\n", i+1, *num_dependency);
                scanf("%u", &dependency_id[i]); // store task id's in an array
                // inform user of invalid input
                if (dependency_id[i] > num_tasks)
                {
                    printf("Dependent task does not exist.\n%s",
                        "Value must be less than number of tasks.\n");
                }
                // asks again if invalid input
            } while (dependency_id[i] < 1 || dependency_id[i] > num_tasks);

            dependency_id[i]--; // adjust to start counting from zero
        }
    }
    bubble_sort(dependency_id, *num_dependency); // sort id's
}

/* Prompts user to get input about the tasks and all related information
 * and store it in a Task structure
 * - Task tasks[]: The array of Tasks the input is stored in
 * - unsigned int *num_tasks: The number of tasks
 */
void get_Task_data(Task tasks[], unsigned int * num_tasks)
{
    int i;

    // prompt user to insert the number of tasks
    puts("How many tasks would you like to add? (1-10)");
    scanf("%u", num_tasks); // store num of tasks in num_tasks
    // prompt user to input details about each task
    for (i = 0; i < *num_tasks; i++)
    {
        // prompts user to enter task name
        puts("Please enter the task name:");
        scanf("%s", tasks[i].name); // store name in char array

        // initialize task id
        tasks[i].id = i;

        // call function to get months input to the current task from user
        get_months(&tasks[i].start_month, &tasks[i].end_month);

        // call function to get dependency input to the current task from user
        get_dependencies(&tasks[i].dependencies, tasks[i].dependency_id, *num_tasks);
    }
}

/* Sets up the program at the beginning, get values for Tasks
 * 1. Ask user where to get values for tasks
 *    a) user input - prompts user to get details about each task
 *    b) test values - inputs test values to struct tasks
 * 2. Stores values in Task tasks
 * - Task tasks[]: array of Task to store the value in
 * - unsigned int *num_tasks: Final number of tasks
 */
void initial_action(Task tasks[], unsigned int *num_tasks)
{
    char response[20];

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
            break; // stop prompting user
        }
        if (strcmp(response, "create") == 0)
        {
            // prompts user to get details about each task
            get_Task_data(tasks, num_tasks);
            break; // stop prompting user
        }
        // inform user that wrong input has been given
        puts("Wrong input - Enter \"test\" or \"create\"");
    } while (1);
}

/* Prompts user to edit a task
 * - Task tasks[]: array of Task for which user picks a task to edit
 * - unsigned int *num_tasks: Number of tasks stored in the array
 */
void action_edit(Task tasks[], unsigned int *num_tasks)
{
    char response[20];
    int i;
    bool found = false;

    // continue getting user input until valid
    do
    {
        puts("Please enter the task name you wish to change exactly");
        scanf("%s", response);

        // go through each task and see if it matches the response
        for (i = 0; i < *num_tasks; i++)
        {
            // if yes, break loop early, change guard
            if (strcmp(tasks[i].name, response) == 0)
            {
                found = true;
                break;
            }
        }
    } while (!found);

    // prompt user to choose new task name
    puts("Please enter the new task or write its old one");
    scanf("%19s", tasks[i].name);

    // get new months
    get_months(&tasks[i].start_month, &tasks[i].end_month);

    // get new dependencies
    get_dependencies(&tasks[i].dependencies, tasks[i].dependency_id, *num_tasks);
}