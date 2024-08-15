#include "utils/menu.h"
#include <windows.h>

void sayHello()
{
    printf("Hello World!\n");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    option options[] = {{"Say Hello", sayHello}};

    menu("My Custom Menu", options, 1, NULL);

    return 0;
}
