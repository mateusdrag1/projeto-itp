#ifndef TERRAIN_H
#define TERRAIN_H

typedef struct
{
  int height;
} Terrain;

void terrain_size(int SIZE, Terrain *terrain, int *vector);

#endif
