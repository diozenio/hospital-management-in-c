#include "app.h"

void app(User* user) {
  switch (user->role) {
    case ADMIN:
      admin_app(user);
      break;
    case NURSE:
      nurse_app();
      break;
    default:
      printf("Acesso negado\n");
      break;
  }
}