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

void display_menu(void);

void initialize_test_values(Task tasks[], unsigned int *num_tasks);

void get_months(unsigned int * start_month, unsigned int * end_month);

void get_dependencies(unsigned int * num_dependency, unsigned int dependency_id[]);

void get_Task_data(Task tasks[], unsigned int * num_tasks);

void initial_action(Task tasks[], unsigned int *num_tasks);

void action_edit(Task tasks[], unsigned int *num_tasks);

#endif //TASKS_H
