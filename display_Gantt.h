//
// Created by David Neškrabal on 06.03.2025.
//

#ifndef DISPLAY_GANTT_H
#define DISPLAY_GANTT_H

#include "tasks.h"

#define CELL_SIZE 10 // the size of cells in a table

/* Prints one character repeatedly, according to the size of the header
 * - char a: character to be printed (usually '-' or '_')
 */
void print_char(char a);

/* Prints a table cell with a sting centered inside
 * careful, only prints the right border ('|')
 * - char *string: string to be inserted and centered
 * - int width: width of the cell
 */
void print_cell(char *string, int width);

/* Prints a header for the Gantt diagram, with month names
 */
void print_header(void);

/* Displays the Gantt diagram of the tasks
 * - Task tasks[]: the array of Tasks to create the diagram from
 * - int num_tasks: Actual number of tasks in the array
 */
void display_Gantt_diagram(Task tasks[], int num_tasks);



#endif //DISPLAY_GANTT_H
