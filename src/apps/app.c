#include "app.h"

void admin_app(User* user) {
  printf("Bem vindo ao sistema hospitalar, %s\n", user->name);
  pause_system();
}

void app(User* user) {
  switch (user->role) {
    case ADMIN:
      admin_app(user);
      break;
    default:
      printf("Acesso negado\n");
      break;
  }
}