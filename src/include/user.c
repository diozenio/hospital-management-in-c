#include "user.h"

char* getUserRole(enum UserRole role) {
    switch (role) {
        case ADMIN:
            return "ADMIN";
        case NURSE:
            return "NURSE";
        case DOCTOR:
            return "DOCTOR";
        default:
            return "UNKNOWN";
    }
}

enum UserRole getUserRoleByString(char* role) {
    if (strcmp(role, "ADMIN") == 0) return ADMIN;
    if (strcmp(role, "NURSE") == 0) return NURSE;
    if (strcmp(role, "DOCTOR") == 0) return DOCTOR;
    return UNKNOWN;
}

void save_user(User* user) {
    char* data = (char*)malloc(sizeof(char));
    sprintf(data, "%d;%s;%s;%s;%s\n", user->id, user->name, user->email, user->password, getUserRole(user->role));
    write_file("src/bin/users.txt", data);
    free(data);
}

User* createUser(enum UserRole role) {
    User* user = (User*)malloc(sizeof(User));
    separator();
    
    printf("Digite o nome completo do usuário: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0;

    printf("Digite o email do usuário: ");
    scanf("%s", user->email);
    getchar();

    printf("Digite a senha do usuário: ");
    scanf("%s", user->password);
    getchar();

    user->role = role;
    user->id = generate_random_id();

    save_user(user);
    return user;
}

void printUser(User* user) {
    printf("ID: %d\n", user->id);
    printf("Nome: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Senha: %s\n", user->password);
    printf("Role: %s\n", getUserRole(user->role));
}

void parseUser(char* userData, User* user) {
    char* token = strtok(userData, ";");

    user->id = atoi(token);

    token = strtok(NULL, ";");
    strcpy(user->name, token);

    token = strtok(NULL, ";");
    strcpy(user->email, token);

    token = strtok(NULL, ";");
    strcpy(user->password, token);

    token = strtok(NULL, ";");
    user->role = getUserRoleByString(token);
}

User* findUserByEmail(char* email) {
    char* data = read_file("src/bin/users.txt");
    char* line_start = data;
    char* line_end;
    
    while ((line_end = strchr(line_start, '\n')) != NULL) {
        *line_end = '\0'; 
        
        User* user = (User*)malloc(sizeof(User));
        char* role = (char*)malloc(sizeof(char));
        parseUser(line_start, user);
        free(role);
        
        if (strcmp(user->email, email) == 0) {
            return user;
        }

        line_start = line_end + 1; 
    }

    if (*line_start != '\0') {
        User* user = (User*)malloc(sizeof(User));
        char* role = (char*)malloc(sizeof(char));
        parseUser(line_start, user);
        free(role);

        if (strcmp(user->email, email) == 0) {
            return user;
        }
    }

    return NULL;
}

