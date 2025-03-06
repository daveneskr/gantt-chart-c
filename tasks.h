//
// Created by David Neškrabal on 06.03.2025.
//

#ifndef TASKS_H
#define TASKS_H

#define MAX_TASKS 10

typedef struct
{
    unsigned int id;
    char name[20];
    unsigned int start_month;
    unsigned int end_month;
    unsigned int dependencies;
    unsigned int dependency_id[MAX_TASKS-1];
} Task;

/* Displays the welcoming message and users options
 */
void display_menu(void);

/* Initialize an array of Task's with test values
 * - Task tasks[]: The array you want the test values to be stored in
 * - unsigned int *num_tasks: The number of tasks of the test values
 */
void initialize_test_values(Task tasks[], unsigned int *num_tasks);

/* Prompts user to input start/end month
 * and store them in the Task structure
 * - unsigned int * start_month: number representing the start month
 * - unsigned int * end_month: number representing the end month
 */
void get_months(unsigned int * start_month, unsigned int * end_month);


/* Gets information about the dependencies of a task
 * - unsigned int * num_dependency: The number of dependencies of a task
 * - unsigned int dependency_id[]: array to store the id of the dependent tasks
 * - int num_tasks: Overall number of tasks
 */
void get_dependencies(unsigned int * num_dependency, unsigned int dependency_id[], int num_tasks);

/* Prompts user to get input about the tasks and all related information
 * and store it in a Task structure
 * - Task tasks[]: The array of Tasks the input is stored in
 * - unsigned int *num_tasks: The number of tasks
 */
void get_Task_data(Task tasks[], unsigned int * num_tasks);

/* Sets up the program at the beginning, get values for Tasks
 * 1. Ask user where to get values for tasks
 *    a) user input - prompts user to get details about each task
 *    b) test values - inputs test values to struct tasks
 * 2. Stores values in Task tasks
 * - Task tasks[]: array of Task to store the value in
 * - unsigned int *num_tasks: Final number of tasks
 */
void initial_action(Task tasks[], unsigned int *num_tasks);

/* Prompts user to edit a task
 * - Task tasks[]: array of Task for which user picks a task to edit
 * - unsigned int *num_tasks: Number of tasks stored in the array
 */
void action_edit(Task tasks[], unsigned int *num_tasks);

#endif //TASKS_H
