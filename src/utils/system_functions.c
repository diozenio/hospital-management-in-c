#include "system_functions.h"

void sleep_system(int seconds) {
    #ifdef _WIN32
    Sleep(seconds * 1000);
    #endif
    #ifdef __APPLE__
    sleep(seconds);
    #endif
}

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef __APPLE__
    system("clear");
    #endif
}