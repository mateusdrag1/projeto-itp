#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "include/functions.h"

int main()
{
  int height = 250, width = 500, interations = 500;
  Point *points = malloc(interations * sizeof(points));
  srand(time(NULL));
  points[0].y = 100 + rand() % (height - 50);
  make_vector(interations, points);
  header_ppm(height, width);
  draw_montain(width, height, points);

  return 0;
}