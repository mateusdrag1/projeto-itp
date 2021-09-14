#include <stdio.h>
#include "../include/terrain.h"

void terrain_size(int SIZE, Terrain *terrain, int *vector)
{
  int i;
  for (i = 0; i < SIZE; i++)
  {
    terrain[i].height = vector[i];
  }
}
