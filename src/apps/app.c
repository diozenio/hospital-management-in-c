#include "app.h"
#include "admin.h"

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