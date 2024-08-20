#include "unauth_app.h"
#include "../include/user.h"

void login() {
  char email[50];
  char password[50];

  printf("Digite seu email: ");
  scanf("%s", email);
  getchar();
  printf("Password: ");
  scanf("%s", password);
  getchar();

  User* user = findUserByEmail(email);

  if (user == NULL) {
    printf("Email ou senha inválidos\n");
    sleep_system(3);
    return;
  }

  if (strcmp(user->password, password) != 0) {
    printf("Email ou senha inválidos\n");
    sleep_system(3);
    return;
  }

  printf("Login realizado com sucesso\n");
  sleep_system(2);
  app(user);
}

void unauth_app() {
  option options[] = {
    {"Login", login, NULL},
  };

  menu("Sistema Hospitalar", options, 1, NULL);
}