#include "menu.h"
#include "system_functions.h"

void separator()
{
    printf("\n--------------------------------\n");
}

void menu(const char *title, option *options, int option_count, option *onExit)
{
    int choice;

    option defaultExitOption = {"Sair", NULL, NULL};

    if (onExit == NULL)
    {
        onExit = &defaultExitOption;
    }

    while (1)
    {
        clear_screen();
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
        getchar();

        if (choice == 0)
        {
            if (onExit->execute != NULL)
            {
                if (onExit->data != NULL)
                    onExit->execute(onExit->data);
                else
                    onExit->execute(NULL);
            }
            break;
        }
        else if (choice > 0 && choice <= option_count)
        {
            clear_screen();
            if (options[choice - 1].data != NULL)
                options[choice - 1].execute(options[choice - 1].data);
            else
                options[choice - 1].execute(NULL);
        }
        else
        {
            separator();
            printf("Opção inválida. Tente novamente.");
            sleep_system(2);

            separator();
        }
    }
}
