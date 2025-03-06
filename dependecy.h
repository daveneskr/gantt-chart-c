//
// Created by David Neškrabal on 03.03.2025.
//

#ifndef DEPENDECY_H
#define DEPENDECY_H

#include "tasks.h"

int check_cycle(Task tasks[], int num_tasks, int task_id, int visited[]);

void print_dependency_tree(Task tasks[], int num_tasks, int task_id);

void print_dependency_chain(Task tasks[], int task_id, int visited[]);

#endif //DEPENDECY_H
