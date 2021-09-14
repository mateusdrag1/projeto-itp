#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"

void make_vector(int n, Point *points)
{
  int i = 0;

  for (i = 1; i < n; ++i)
  {
    points[i].y = (points[i - 1].y + ((rand() % 3)) - 1);
  }
}

void header_ppm(int x, int y)
{

  FILE *fp = fopen("terrain.ppm", "w");
  fprintf(fp, "P3\n");
  fprintf(fp, "%d %d\n", y, x);
  fprintf(fp, "255\n");
  fclose(fp);
}

void draw_montain(int x, int y, Point *vetor)
{

  int j, k;
  FILE *fp = fopen("terrain.ppm", "a");
  for (j = 0; j < y; ++j)
  {

    for (k = 0; k < x; ++k)
    {

      if (j == vetor[k].y || j > vetor[k].y)
      {
        fprintf(fp, "%d %d %d\n", 25, 29, 76);
      }
      else
      {
        fprintf(fp, "%d %d %d\n", 17, 14, 25);
      }
    }
  }
  fclose(fp);
}