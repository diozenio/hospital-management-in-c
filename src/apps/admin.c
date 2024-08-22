#include "admin.h"

void create_nurse() {
  createUser(NURSE);
}

void create_doctor() {
  createUser(DOCTOR);
}

void admin_app(User* user) {
  option options[] = {
    {"Cadastrar Enfermeira", create_nurse, NULL},
    {"Cadastrar Médico", create_doctor, NULL},
  };

  option exitOption = {"Deslogar", NULL, NULL};

  char* welcomeMessage = (char*)malloc(sizeof(char));
  sprintf(welcomeMessage, "Bem-vindo, administrador %s!", user->name);

  menu(welcomeMessage, options, 2, &exitOption);
  free(welcomeMessage);
}