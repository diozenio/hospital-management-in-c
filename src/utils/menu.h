#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *label;
    void (*execute)(void*);
    void* data;
} option;

void separator();

void menu(const char *title, option *options, int option_count, option *onExit);

#endif
