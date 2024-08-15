#include "utils/menu.h"
#ifdef _WIN32
#include <windows.h>
#endif

void sayHello()
{
    printf("Hello World!\n");
}

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    option options[] = {{"Say Hello", sayHello}};

    menu("My Custom Menu", options, 1, NULL);

    return 0;
}
