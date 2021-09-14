#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/vector.h"

#define average(a, b) ((a + b) / 2)

void makeMountain(int right, int left, int *vector, float random_displacement, int ratio);

float random_float(float max)
{
  float randomN;
  randomN = ((float)rand() / (float)(RAND_MAX)*max);
  return randomN;
}

int random_int(int max)
{
  int randomN;
  do
  {
    randomN = rand() % max;
  } while (randomN > 0);
  return randomN;
}

int sortedValue(int maxHeight)
{
  int value;
  value = random_int(maxHeight - 1);
  return value;
}

void create_vector(int *vector, int size)
{
  int i;
  srand(time(NULL));
  for (i = 0; i < size; i++)
  {
    vector[i] = 0;
  }
}

void setDisplacement(int right, int left, int middle, int *vector, int ratio)
{

  vector[middle] = average(vector[left], vector[right]);
  vector[middle] += (random_float(1.0) * ratio * 2) - ratio;
}

void makeMountain(int right, int left, int *vector, float random_displacement, int ratio)
{
  if (right - left > 1 && right > 1)
  {
    int middle = average(right, left);
    setDisplacement(right, left, middle, vector, ratio);

    ratio *= random_displacement;
    makeMountain(right, middle, vector, random_displacement, ratio);

    ratio *= random_displacement;
    makeMountain(middle, left, vector, random_displacement, ratio);
  }
}

void generate_vector(int width, int *vector, int height, float random_displacement)
{
  int ratio = height / 4;

  vector[width - 1] = height / 2 + (random_float(1.0) * ratio * 2) - ratio;
  vector[0] = height / 2 + (random_float(1.0) * ratio * 2) - ratio;

  ratio *= random_displacement;
  setDisplacement(width - 1, 0, width / 2, vector, ratio);

  ratio *= random_displacement;
  makeMountain(width / 2, 0, vector, random_displacement, ratio);

  ratio *= random_displacement;
  makeMountain(width - 1, width / 2, vector, random_displacement, ratio);
}