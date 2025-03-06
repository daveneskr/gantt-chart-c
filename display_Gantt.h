//
// Created by David Neškrabal on 06.03.2025.
//

#ifndef DISPLAY_GANTT_H
#define DISPLAY_GANTT_H

#include "tasks.h"

void print_char(char a);

void print_cell(char *string, int width);

void print_header(void);

void display_Gantt_diagram(Task tasks[], int num_tasks);



#endif //DISPLAY_GANTT_H
