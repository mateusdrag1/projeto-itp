#ifndef IMAGEM_H
#define IMAGEM_H

#include "terrain.h"

typedef struct
{
  unsigned int r;
  unsigned int g;
  unsigned int b;
} PIXEL;

void setBackground(int x, int y, PIXEL **image);
void drawTerrain(int x, int y, int *vector, PIXEL **image);

#endif