#ifndef SYSTEM_FUNCTIONS_H
#define SYSTEM_FUNCTIONS_H

#ifdef _WIN32
#include <windows.h>
#endif
#ifdef __APPLE__
#include <unistd.h>
#include <stdlib.h>
#endif
#include <stdio.h>

void sleep_system(int seconds);
void clear_screen();
void pause_system();

#endif