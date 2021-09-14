#ifndef _FUNCTIONS
#define _FUNCTIONS

typedef struct
{
  int x;
  int y;
} Point;

void make_vector(int n, Point *points);
void header_ppm(int x, int y);
void draw_montain(int x, int y, Point *vetor);

#endif