#ifdef _WIN32
#include <windows.h>
#endif

#include "apps/unauth_app.h"

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    unauth_app();
   
    return 0;
}
