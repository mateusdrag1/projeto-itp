#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/image.h"

void drawPixel(PIXEL colors, int x, int y, PIXEL **image)
{
  image[y][x] = colors;
}

void setBackground(int x, int y, PIXEL **image)
{
  int i, j;
  PIXEL colors = {240, 203, 163};
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < x; j++)
    {
      drawPixel(colors, j, i, image);
    }
  }
}

void drawTerrain(int x, int y, int *vector, PIXEL **image)
{
  PIXEL colors = {158, 98, 204};
  int i, j = 0;
  for (i = 0; i < x; i++)
  {
    for (j = vector[i]; j < y; j++)
    {
      drawPixel(colors, i, j, image);
    }
  }
}
