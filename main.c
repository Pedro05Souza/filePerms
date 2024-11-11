#include "stdio.h"
#include "user.h"
#include "file.h"

#define READ 0b0001
#define WRITE 0b0010

unsigned int getPermission(unsigned int* permissionInput){
    if(*permissionInput == 1){
        return READ;
    } else if(*permissionInput == 2){
        return WRITE;
    }
    else{
        unsigned int moveLeft = READ << 4; 
        return moveLeft | WRITE;
    }
}

struct User newUser() {
    char name[100];
    unsigned int permissions;
    printf("Enter the name of the user:");
    scanf("%s", name);
    printf("Select the permissions of the user:\n");
    printf("[1]. Read\n");
    printf("[2]. Write\n");
    printf("[3]. Read and Write\n");
    scanf("%u", &permissions);

    unsigned int permissionBin = getPermission(&permissions);
    return createUser(name, &permissionBin);
}

struct File newFile() {
    char description[100];
    unsigned int permissions;
    printf("Enter the description of the file:");
    scanf("%s", description);
    printf("Select the permissions of the file:\n");
    printf("[1]. Read\n");
    printf("[2]. Write\n");
    printf("[3]. Read and Write\n");
    scanf("%u", &permissions);

    unsigned int permission = getPermission(&permissions);
    return createFile(description, &permission);
}

int main() {
    struct User user = newUser();
    struct User* userP = &user;
    struct File file = newFile();
    struct File* fileP = &file;

    printf("User: %s\n", userP->name);
    while (1) {
        printf("[1]. Check permissions\n");
        printf("[2]. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            int hasPermission = userHasPermission(fileP, userP);
            if (hasPermission) {
                printf("The user has permission\n");
                printf("Description: %s\n", fileP->description);
            } else {
                printf("The user does not have the necessary permissions\n");
            }
        } else if (option == 2) {
            break;
        }
    }
}
