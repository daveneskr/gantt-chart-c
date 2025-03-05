//
// Created by David Neškrabal on 03.03.2025.
//

#include "dependecy.h"
#include "my_library.h"
#include <stdio.h>

void print_dependency_chain(Task tasks[], int task_id, int visited[])
{
    static int depth = 0;

    if (depth < 0)
    {
        depth = 0;
    }

    if (visited[task_id])  // if task is already visited in this recursion, cycle detected
    {
        printf(" -> %d !! Circular dependency detected !!\n", task_id+1);
        depth--;
        return;
    }

    visited[task_id] = 1; // mark task as visited in current path

    if (tasks[task_id].dependencies == 0)
    {
        printf(" -> %d\n", task_id+1);
        visited[task_id] = 0;
        depth--;
        return;
    }

    for (int i = 0; i < tasks[task_id].dependencies; i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < depth; j++)
            {
                printf("     ");
            }
        }
        printf(" -> %d", task_id+1);
        depth++;
        print_dependency_chain(tasks, tasks[task_id].dependency_id[i], visited);
    }

    visited[task_id] = 0;
    depth--;
}