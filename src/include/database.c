#include "database.h"

void write_file(char *filename, char *data)
{
    FILE *file = fopen(filename, "a");
    fprintf(file, "%s", data);
    fclose(file);
}

void read_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    fclose(file);
}

void delete_file(char *filename)
{
    remove(filename);
}