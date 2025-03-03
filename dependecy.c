//
// Created by David Neškrabal on 03.03.2025.
//

#include "dependecy.h"
#include "my_library.h"
#include <stdio.h>

void print_dependency_chain(Task tasks[], int task_id, int visited[])
{
    if (visited[task_id])  // if task is already visited in this recursion, cycle detected
    {
        printf(" !! Circular dependency detected involving task %d (%s) !!\n", task_id+1, tasks[task_id].name);
        return;
    }

    visited[task_id] = 1; // mark task as visited in current path

    if (tasks[task_id].dependencies == 0)
    {
        printf(" → %s\n", tasks[task_id].name);
        visited[task_id] = 0;
        return;
    }

    for (int i = 0; i < tasks[task_id].dependencies; i++)
    {
        printf(" → %s", tasks[task_id].name);
        print_dependency_chain(tasks, tasks[task_id].dependency_id[i], visited);
    }

    visited[task_id] = 0;
}