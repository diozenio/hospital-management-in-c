#include "menu.h"
#include <windows.h>

void separator()
{
    printf("\n--------------------------------\n");
}

void menu(const char *title, option *options, int option_count, option *onExit)
{
    int choice;

    option defaultExitOption = {"Exit", NULL};

    if (onExit == NULL)
    {
        onExit = &defaultExitOption;
    }

    while (1)
    {
        system("cls");
        separator();
        printf("%s", title);
        separator();

        for (int i = 0; i < option_count; i++)
        {
            printf("%d. %s\n", i + 1, options[i].label);
        }

        printf("\n0. %s", onExit->label);
        separator();

        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            if (onExit->execute != NULL)
            {
                onExit->execute();
            }
            break;
        }
        else if (choice > 0 && choice <= option_count)
        {
            options[choice - 1].execute();
        }
        else
        {
            separator();
            printf("Opção inválida. Tente novamente.");
            Sleep(2000);

            separator();
        }
    }
}
