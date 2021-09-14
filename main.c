#include <stdio.h>
#include <stdlib.h>

#include "./include/image.h"
#include "./include/terrain.h"
#include "./include/file_manipulation.h"
#include "./include/vector.h"

#define WIDTH 500
#define HEIGHT 250
#define RANDOM_DISPLACEMENT 0.7

PIXEL **array_allocation(int x, int y)
{
  PIXEL **array;
  int i;

  array = (PIXEL **)malloc(sizeof(PIXEL *) * y);

  for (i = 0; i < y; i++)
  {
    array[i] = (PIXEL *)malloc(sizeof(PIXEL) * x);
  }

  return array;
}

int getStringSize(char *string)
{
  int i = 0;
  while (string[i] != '\0')
  {
    i++;
  }
  return ++i;
}

void exceptionError()
{
  printf("Você usou parametros inválidos, ATENÇÃO!\n");
  printf("Uso: ./terreno -d 0.8 -o montain.ppm\n");
  printf("Onde -d <num> define o deslocamento aleatório máximo a ser usado na geração.");
  printf("Onde -o <arq> define o nome do arquivo de imagem a ser gerado.");
}

int main(int argc, char *argv[])
{
  int x = WIDTH, y = HEIGHT;
  int hasFile = 0;
  char *imageFile;
  float k = RANDOM_DISPLACEMENT;
  if (argc > 2)
  {
    int i = 1, j = 0, size;
    while (i < argc)
    {
      if (argv[i][j] == '-')
      {
        j++;
        switch (argv[i][j])
        {
        case 'd':
          k = atof(argv[++i]);
          if (k > 0.9 || k == 0.0)
          {
            exceptionError();
            return 1;
          }
          i++;
          j = 0;
          break;
        case 'o':
          size = getStringSize(argv[++i]);
          if (size > 5)
          {
            if ((argv[i][size - 5] == '.') && (argv[i][size - 4] == 'p') && (argv[i][size - 3] == 'p') && (argv[i][size - 2] == 'm'))
            {
              hasFile = 1;
              imageFile = argv[i];
            }
            else
            {
              exceptionError();
              return 1;
            }
          }
          else
          {
            exceptionError();
            return 1;
          }
          j = 0;
          i++;
          break;
        default:
          exceptionError();
          return 1;
        }
      }
      else
      {
        exceptionError();
        return 1;
      }
    }
  }
  else if (argc == 2)
  {
    exceptionError();
    return 1;
  }

  if (!hasFile)
  {
    imageFile = (char *)malloc(sizeof(char) * 10);
    imageFile = "montain.ppm";
  }

  PIXEL **image = array_allocation(x, y);
  int *vector = (int *)malloc(sizeof(int) * x);

  create_vector(vector, x);
  generate_vector(x, vector, y, k);
  setBackground(x, y, image);
  drawTerrain(x, y, vector, image);

  createFile(&x, &y, imageFile);
  saveFile(x, y, image, imageFile);

  return 0;
}
