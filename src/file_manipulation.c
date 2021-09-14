#include <stdio.h>
#include "../include/file_manipulation.h"

void header(FILE *file, int *x, int *y)
{
  fprintf(file, "P3\n");
  fprintf(file, "%d %d\n", *x, *y);
  fprintf(file, "255\n");
}

int createFile(int *x, int *y, char *file_name)
{
  FILE *file;
  file = fopen(file_name, "w+");
  header(file, x, y);
  fclose(file);
  return 0;
}

int saveFile(int x, int y, PIXEL **image, char *file_name)
{
  FILE *file;
  file = fopen(file_name, "a");
  int i, j;
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < x; j++)
    {
      fprintf(file, "%i %i %i\n", image[i][j].r, image[i][j].g, image[i][j].b);
    }
  }

  fclose(file);
  return 0;
}