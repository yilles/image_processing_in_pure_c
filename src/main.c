#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "img_process.h"

#ifdef DEBUG
int main(void)
{
  char filename[20];
  char filename2[20];
  char *data = NULL;
  char *palette = NULL;
  char *header = NULL;
  clock_t int_time, end_time;
  int msec;

  printf("It is in debug mode.\n");
  printf("Reading image file: ");
  scanf("%20s", filename);
  printf("Writing image file: ");
  scanf("%20s", filename2);
  int_time = clock();
  //for (int i = 0; i < 10000; i++)
  for (int i = 0; i < 1; i++)
  {
    if (bmp_read(filename, &data, &palette, &header) != 0)
      printf("Can't find or open the image file: %s.\n", filename);
    else
      printf("%d-Read-OK\n", i + 1);

    if (bmp_rotage(20, &data, &palette, &header) != 0)
      printf("Rotage fail\n");
    else
    {
      printf("%d-Rotage-OK\n", i + 1);
      int width, height;
      memcpy(&width, header + 18, sizeof(int));
      memcpy(&height, header + 22, sizeof(int));
      printf("%d\n", width);
      printf("%d\n", height);
    }

    if (bmp_write(filename2, data, palette, header) != 0)
      printf("Can't find or open the image file: %s.\n", filename2);
    else
      printf("%d-Write-OK\n", i + 1);

    free(data);
    free(palette);
    free(header);
  }
  end_time = clock();
  msec = (end_time - int_time) * 1000 / CLOCKS_PER_SEC;
  printf("It cost %d ms to run.", msec);
  return 0;
}
#else
int main(void)
{
  char *filename = "image.bmp";
  char *data = NULL;
  char *palette = NULL;
  char *header = NULL;

  if (bmp_read(filename, &data, &palette, &header) != 0)
    printf("Can't find or open the image file: %s\n", filename);
  else
    printf("OK\n");

  free(data);
  free(palette);
  free(header);
  return 0;
}
#endif // DEBUG
