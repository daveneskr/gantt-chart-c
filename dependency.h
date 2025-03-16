// Created by Zhang Beichen

#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "my_library.h"
#include "tasks.h"

void print_dependency_chain(Task tasks[], int task_id, int visited[]);

#endif // DEPENDENCY_H
