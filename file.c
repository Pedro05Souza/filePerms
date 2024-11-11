#include "file.h"
#include "stdio.h"
#include "string.h"

struct File createFile(char* description, unsigned int* permissions){
    struct File file;
    strcpy(file.description, description);
    file.permissionsRequired = *permissions;
    return file;
}

void alterFilePermission(struct File* file, unsigned int* permission){
    if(file->permissionsRequired != 18){
        unsigned int* newPermission = file->permissionsRequired | *permission;
        printf("%d\n", &newPermission);
        newPermission = *newPermission ^ *permission;
        printf("%d\n", &newPermission);
    }else{
        file->permissionsRequired = 18;
    }
    
}