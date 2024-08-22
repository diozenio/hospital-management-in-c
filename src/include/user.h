#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include "../utils/menu.h"
#include "../utils/system_functions.h"
#include "../utils/generate_random_id.h"
#include "database.h"

enum UserRole {
  ADMIN,
  DOCTOR,
  NURSE,
  UNKNOWN
};

typedef struct {
  int id;
  char name[100];
  char email[50];
  char password[50];
  enum UserRole role;
} User;

User* createUser(enum UserRole role);
User* findUserByEmail(char* email);

char* getUserRole(enum UserRole role);
void printUser(User* user);

#endif