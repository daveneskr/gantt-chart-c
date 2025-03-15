//
// Created by David Neškrabal on 03.03.2025.
//

#include "dependency_d.h"
#include <stdio.h>

/* Recursively prints the dependency chain of a given task,
 * indicating circular dependencies if found.
 * - Task tasks[]: array of tasks
 * - int task_id: the id of the current task
 * - int visited[]: array used to track visited tasks
 */
void print_dependency_chain_d(Task tasks[], int task_id, int visited[])
{
    static int depth = 0; // keep track depth level
    depth++; // increase depth when entering the function

    // if task is already visited in this recursion, cycle detected
    if (visited[task_id])
    {
        printf("->%2d !! Circular dependency detected !!\n", task_id+1);
        depth--;
        return;
    }

    visited[task_id] = 1; // mark task as visited in current path

    // base case, no dependencies
    if (tasks[task_id].dependencies == 0)
    {
        printf("->%2d \n", task_id+1);
        visited[task_id] = 0; // un-flag task
        depth--; // decrease depth when leaving the function
        return;
    }

    // look through all dependencies
    for (int i = 0; i < tasks[task_id].dependencies; i++)
    {
        // if branched, indent branch based on depth
        if (i > 0)
        {
            for (int j = 0; j < depth-1; j++)
            {
                printf("     ");
            }
        }
        printf("->%2d ", task_id+1);
        print_dependency_chain_d(tasks, tasks[task_id].dependency_id[i], visited);
    }

    visited[task_id] = 0; // un-flag task
    depth--; // decrease depth when leaving the function
}