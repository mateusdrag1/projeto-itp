#ifndef MANIPULATION_H
#define MANIPULATION_H
#include "image.h"

int createFile(int *x, int *y, char *file_name);
int saveFile(int x, int y, PIXEL **image, char *file_name);

#endif