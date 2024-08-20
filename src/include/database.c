#include "database.h"

void write_file(char *filename, char *data)
{
    FILE *file = fopen(filename, "a");
    fprintf(file, "%s", data);
    fclose(file);
}

char* read_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    char *data = malloc(1024);
    fread(data, 1, 1024, file);
    fclose(file);
    return data;
}

void delete_file(char *filename)
{
    remove(filename);
}