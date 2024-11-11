#ifndef USER_H
#define USER_H

#include "file.h"

struct User {
    char name[100];
    unsigned int permissions;
};

struct User createUser(char* name, unsigned int* permissions);

int userHasPermission(struct File* file, struct User* user);

void alterUserPermission(struct User* user, unsigned int* permission);


#endif