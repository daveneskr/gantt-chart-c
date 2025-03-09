// Created by Zhang Beichen

#include "dependency.h"
#include <stdio.h>
#include <stdbool.h>

// Functions to check and print dependency chains while detecting circular dependencies.

static int check_circular_dependency(Task tasks[], int task_id, int visited[])
{
	static bool flag = true; // To control whether to print the arrow separator on the next line.

    // If the current task has appeared in the recursive path, a circular dependency is found.
    if (visited[task_id])
    {
        printf(" (!!!!!!!!!! warning potential circular dependency !!!!!!!!!!)\n");
        fflush(stdout);
        flag = false; // Next line break control.
        return 1;
    }

    // Mark the current task as visited.
    visited[task_id] = 1;

    // Print the current task's identifier, 0-indexed to 1-indexed.
    printf("%d", task_id + 1);
    fflush(stdout);

    int cycle_state = 0; // Indicate whether a circular dependency is detected.

    // Iterate over all dependencies of the current task.
    for (int i = 0; i < tasks[task_id].dependencies; i++)
    {
        // Print the arrow separator between dependencies if flag.
    	if (flag == true)
    	{
            printf(" -> ");
            fflush(stdout);
    	}
    	else
    	{
    		// The first identifier does not print the arrow separator.
    		flag = true; // Next line break control.
    	}
        // Recursively process the dependency.
    	// If the recursive call returns 1, a circular dependency was detected in a deeper level.
        if (check_circular_dependency(tasks, tasks[task_id].dependency_id[i], visited))
        {
            cycle_state = 1;
        }
    }

    // Return the cycle_state indicating if a circular dependency was detected.
    return cycle_state; // 1 means detected.
}

void print_dependency_chain(Task tasks[], int task_id)
{
    int visited[MAX_TASKS] = {0};  // Initialize the visited array to mark all tasks as not visited.

    // Call the recursive function to print the dependency chain.
    int cycle = check_circular_dependency(tasks, task_id, visited);

    // If a circular dependency is detected, print an additional warning message.
    if (cycle)
    {
        printf("!!! Circular Dependency Found !!!\n");
        fflush(stdout);
    }
}
