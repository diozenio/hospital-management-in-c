#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_file(char *filename, char *data);
char* read_file(char *filename);
void delete_file(char *filename);

#endif


