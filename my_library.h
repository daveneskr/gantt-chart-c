//
// Created by David Neškrabal on 20.02.2025.
//

#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

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

void print_char(char a);

void print_cell(char *string, int width);

void print_header(void);

void get_months(unsigned int * start_month,unsigned int * end_month);

void swap(unsigned int *a, unsigned int *b);

void bubble_sort(unsigned int arr[], unsigned int size);

void get_dependencies(unsigned int * num_dependency, unsigned int dependency_id[]);

void get_Task_data(Task tasks[], unsigned int * num_tasks);

void display_Gantt_diagram(Task tasks[], int num_tasks);

void initial_action(Task tasks[], unsigned int *num_tasks);

void action_edit(Task tasks[], unsigned int *num_tasks);

#endif //MY_LIBRARY_H
