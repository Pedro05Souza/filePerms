#include "user.h"
#include "file.h"
#include "string.h"

struct User createUser(char* name, unsigned int* permissions) {
    struct User user;
    strcpy(user.name, name);
    user.permissions = *permissions;
    return user;
}

int userHasPermission(struct File* file, struct User* user) {
    unsigned int isValuated = file->permissionsRequired & user->permissions;
    return isValuated == user->permissions;
}

void alterUserPermission(struct User* user, unsigned int* permission){
    user->permissions = *permission;
}
