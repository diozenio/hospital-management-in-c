#include "admin.h"

const char *WELCOME_TEMPLATE = "Bem-vindo, administrador %s!";

void create_nurse()
{
  createUser(NURSE);
}

void create_doctor()
{
  createUser(DOCTOR);
}

char *createWelcomeMessage(const char *userName)
{
  size_t size = strlen(WELCOME_TEMPLATE) + strlen(userName) + 1;
  char *message = (char *)malloc(size);
  sprintf(message, WELCOME_TEMPLATE, userName);
  return message;
}

void admin_app(User *user)
{
  option options[] = {
      {"Cadastrar Enfermeira", create_nurse, NULL},
      {"Cadastrar Médico", create_doctor, NULL},
  };

  option exitOption = {"Deslogar", NULL, NULL};

  char *welcomeMessage = createWelcomeMessage(user->name);

  menu(welcomeMessage, options, 2, &exitOption);
  free(welcomeMessage);
}