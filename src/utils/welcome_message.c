#include "welcome_message.h"

char *createWelcomeMessage(char *userName)
{
    const char *WELCOME_TEMPLATE = "Bem-vindo, %s!";

    size_t size = strlen(WELCOME_TEMPLATE) + strlen(userName) + 1;
    char *message = (char *)malloc(size);
    sprintf(message, WELCOME_TEMPLATE, userName);

    return message;
}