#ifndef FILEPERMISSIONS_H
#define FILEPERMISSIONS_H

struct File {
    char description[100];
    unsigned int permissionsRequired;
};

struct File createFile(char* description, unsigned int* permissionsRequired);

void alterFilePermission(struct File* file, unsigned int* permission);

#endif
